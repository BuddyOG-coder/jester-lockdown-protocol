#ifndef GAME_FUNCTIONS_HPP
#define GAME_FUNCTIONS_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include "game_structures.hpp"
#include "util.hpp"
#include "mem.hpp"

using namespace protocol::engine::sdk;
using namespace protocol::game::sdk;
using namespace protocol::engine;

// Global item class mapping
inline std::unordered_map<std::string, std::string> item_class_map = {
	{"SHORTY", "DA_Shorty"},
	{"REVOLVER", "DA_Revolver"},
	{"PISTOL", "DA_Pistol"},
	{"SHOTGUN", "DA_Shotgun"},
	{"SMG", "DA_SMG"},
	{"RIFLE", "DA_Rifle"},
	{"DETONATOR", "DA_Detonator"},
	{"C4", "DA_C4"},
	{"KNIFE", "DA_Knife"},
	{"FUSE", "DA_Fuse"},
	{"BATTERY", "DA_Battery"},
	{"GAZ BOTTLE", "DA_GazBottle"}, // Updated to match fallback
	{"VENT", "DA_Vent"},
	{"SCREW DRIVER", "DA_ScrewDriver"}, // Updated to match fallback
	{"CONTAINER", "DA_Container"},
	{"PIZZUSHI", "DA_Pizzushi"},
	{"CASSETTE", "DA_Cassette"}, // Updated to match fallback
	{"SAMPLE", "DA_Sample"},
	{"RICE", "DA_Rice"},
	{"PACKAGE", "DA_Package"}
};

std::vector<uintptr_t> find_objects(const std::string& name_find);

u_data_item* AssignToItemData(const std::string& target_name);

// Check if an object matches a class name
inline bool is_a(uintptr_t object_address, const std::string& class_name, bool exact_match = false) {
	if (!object_address) return false;

	auto object = reinterpret_cast<u_object*>(object_address);
	auto object_class = object->class_private();

	while (object_class) {
		int fname_idx = object_class->fname_index();
		std::string current_class_name = util::get_name_from_fname(fname_idx);

		if (exact_match) {
			if (current_class_name == class_name) return true;
		}
		else {
			if (current_class_name.find(class_name) != std::string::npos) return true;
		}

		object_class = object_class->super();
	}

	return false;
}

// Function to capitalize strings
inline std::string ToUpperCase(const std::string& str) {
	std::string upper_case = str;
	std::transform(upper_case.begin(), upper_case.end(), upper_case.begin(), ::toupper);
	return upper_case;
}

// Find objects by name
inline std::vector<uintptr_t> find_objects(const std::string& name_find) {
	std::vector<uintptr_t> objs;
	constexpr auto elements_per_chunk = 64 * 1024;
	auto gobjects = mem::rpm<fuobjectarray>(mem::module_base + GOBJECTS);

	for (int i = 0; i < gobjects.num_chunk; i++) {
		auto chunk_start = mem::rpm<uintptr_t>(gobjects.chunk_table + (i * 0x8));
		for (int j = 0; j < elements_per_chunk; j++) {
			auto item = mem::rpm<fuobjectitem>(chunk_start + (j * sizeof(fuobjectitem)));
			if (item.object == 0) continue;

			auto obj = reinterpret_cast<u_object*>(item.object);
			std::string name = util::get_name_from_fname(obj->fname_index());
			std::string class_name = util::get_name_from_fname(obj->class_private()->fname_index());

			if (name.find(name_find) != std::string::npos) {
				objs.push_back(item.object);
			}
		}
	}
	return objs;
}

// Assign item data
// Assign item data
inline u_data_item* AssignToItemData(const std::string& target_name) {
	// Debugging: Log the target name
	std::cout << "AssignToItemData called with: " << target_name << std::endl;

	// Convert target_name to uppercase
	std::string upper_name = ToUpperCase(target_name);
	std::cout << "Converted name to uppercase: " << upper_name << std::endl;

	// Check if the name exists in item_class_map
	if (item_class_map.find(upper_name) == item_class_map.end()) {
		std::cerr << "Error: Item class not found for: " << upper_name << std::endl;
		return nullptr;
	}

	// Map the name
	std::string mapped_name = item_class_map[upper_name];
	std::cout << "Mapped name: " << mapped_name << std::endl;

	// Find objects
	std::vector<uintptr_t> found_objects = find_objects(mapped_name);
	std::cout << "Found " << found_objects.size() << " objects for: " << mapped_name << std::endl;

	// Fallback for KNIFE or ambiguous matches
	if (found_objects.empty() && upper_name == "KNIFE") {
		std::cout << "No objects found. Attempting fallback for KNIFE." << std::endl;
		found_objects = find_objects("Knife");
		std::cout << "Fallback for KNIFE found " << found_objects.size() << " objects." << std::endl;
	}

	if (upper_name == "DETONATOR") {
		std::cout << "Explicit fallback for DETONATOR." << std::endl;
		found_objects = find_objects("Detonator");
	}

	if (upper_name == "C4") {
		std::cout << "Explicit fallback for C4." << std::endl;
		found_objects = find_objects("C4");
	}


	// Check if objects are still empty
	if (found_objects.empty()) {
		std::cerr << "Error: No objects found for: " << mapped_name << std::endl;
		return nullptr;
	}



	// Select a valid object
	uintptr_t selected_object = 0;
	for (uintptr_t obj_addr : found_objects) {
		auto obj = reinterpret_cast<u_object*>(obj_addr);
		std::string obj_name = util::get_name_from_fname(obj->fname_index());
		std::string class_name = util::get_name_from_fname(obj->class_private()->fname_index());

		// Debug object name and class
		std::cout << "Found object: " << obj_name << ", class: " << class_name << std::endl;

		// Match all special items
		if (obj_name.find(mapped_name) != std::string::npos) {
			if ((upper_name == "KNIFE" && is_a(obj_addr, "Data_Melee_C")) ||
				(upper_name == "DETONATOR" && is_a(obj_addr, "Data_Melee_C")) ||
				(upper_name == "C4" && is_a(obj_addr, "Data_Melee_C")) ||
				(upper_name == "FUSE" && is_a(obj_addr, "Data_Melee_C")) ||
				(upper_name == "BATTERY" && is_a(obj_addr, "Data_Item_C")) ||
				(upper_name == "GAZ BOTTLE" && is_a(obj_addr, "Data_Item_C")) ||
				(upper_name == "VENT" && is_a(obj_addr, "Data_Item_C")) ||
				(upper_name == "SCREW DRIVER" && is_a(obj_addr, "Data_Item_C")) ||
				(upper_name == "CONTAINER" && is_a(obj_addr, "Data_Item_C")) ||
				(upper_name == "PIZZUSHI" && is_a(obj_addr, "Data_Item_C")) ||
				(upper_name == "SAMPLE" && is_a(obj_addr, "Data_Item_C")) ||
				(upper_name == "RICE" && is_a(obj_addr, "Data_Item_C")) ||
				(upper_name == "PACKAGE" && is_a(obj_addr, "Data_Item_C")) ||
				(upper_name == "SHORTY" && is_a(obj_addr, "Data_Gun_C")) ||
				(upper_name == "REVOLVER" && is_a(obj_addr, "Data_Gun_C")) ||
				(upper_name == "PISTOL" && is_a(obj_addr, "Data_Gun_C")) ||
				(upper_name == "SHOTGUN" && is_a(obj_addr, "Data_Gun_C")) ||
				(upper_name == "SMG" && is_a(obj_addr, "Data_Gun_C")) ||
				(upper_name == "RIFLE" && is_a(obj_addr, "Data_Gun_C"))) {
				selected_object = obj_addr;
				break; // Stop searching once a valid match is found
			}
		}
		// Hotkeys made by Jester
	}

	if (selected_object != 0) {
		auto obj = reinterpret_cast<u_object*>(selected_object);
		std::string obj_name = util::get_name_from_fname(obj->fname_index());
		return reinterpret_cast<u_data_item*>(selected_object);
	}

	return nullptr;
}

#endif
