#pragma once

#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace config {
	// Hotkeys
	inline int menu_hotkey = VK_F1;
	inline int esp_hotkey = VK_F2;
	inline int speedhack_hotkey = VK_F3;
	inline int god_mode_hotkey = VK_F4;
	inline int infinite_stamina_hotkey = VK_F5;
	inline int fast_melee_hotkey = VK_F6;
	inline int infinite_melee_range_hotkey = VK_F7;
	inline int auto_fire_hotkey = VK_F8;
	inline int rapid_fire_hotkey = VK_F9;
	inline int no_recoil_hotkey = VK_INSERT;
	inline int max_damage_hotkey = VK_DELETE;
	inline int aimbot_hotkey = VK_PRIOR;

	// Player
	inline bool speedhack = false;
	inline double max_speed = 2000.00; // 800.0 is default value run speed
	inline double friction = 100000.00; // 0.0 is default value friction
	inline bool infinite_stamina = false;
	inline bool god_mode = false;
	inline bool aimbot = false;

	// Weapons
	// Melee
	inline bool fast_melee = false;
	inline double cast_time = 0.0; // avg is 0.1 : 0.5
	inline double recover_time = 0.0; // avg is 0.4 : 1.0
	inline double stun = 1.0; // avg is -1 : 0.4
	inline int cost = 0; // avg is 20 : 40
	inline bool infinite_melee_range = false;
	inline int range = 10000; // avg is 130 : 180
	// Guns
	inline bool max_damage = false;
	inline bool auto_fire = false;
	inline bool rapid_fire = false;
	inline double rapid_fire_rate = 0.02; // avg 0.07 : 0.3
	inline bool no_recoil = false;
	inline double movement_osc = 0.0; // avg 0.3 : 20
	inline double osc_reactivity = 0.0; // avg 4 : 100
	inline double movement_prec = 0.0; // avg 0.5 : 40
	inline double recoil_react = 0.0; // avg 1 : 40
	inline double shake_intensity = 0.0; // avg 0.5 : 5
	inline double fire_spread = 0.0;
	inline bool infinite_ammo = false;
	inline int ammo_count = 12;

	// Inventory
	inline bool can_inventory = false;

	// ESP
	inline bool esp_enabled = true;
	inline double esp_max_distance = 70.0;

	inline bool esp_radar = true;
	inline std::string esp_radar_position = "Middle Right";
	inline double esp_radar_scale = 0.10;

	inline bool player_esp = true;
	inline bool player_distance = true;
	inline bool player_box = true;
	inline bool player_radar = true;
	
	inline ImVec4 employee_color = ImVec4(0.0f, 1.0f, 0.0f, 1.0f); // Green
	inline ImVec4 dissident_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // Red 

	inline bool weapon_esp = true;
	inline bool weapon_item_state = true;
	inline bool weapon_distance = false;
	inline bool weapon_radar = true;
	inline ImVec4 weapon_color = ImVec4(250.0f / 255.0f, 92.0f / 255.0f, 0.0f / 255.0f, 1.0f); // Orange

	inline bool primary_object_esp = true;
	inline bool primary_item_state = false;
	inline bool primary_distance = false;
	inline bool primary_radar = false;
	inline ImVec4 gaz_bottle_color = ImVec4(0.0f / 255.0f, 83.0f / 255.0f, 250.0f / 255.0f, 1.0f); // Blue
	inline ImVec4 vent_filter_color = ImVec4(65.0f / 255.0f, 115.0f / 255.0f, 217.0f / 255.0f, 1.0f); // Light Blue
	inline ImVec4 rice_color = ImVec4(201.0f / 255.0f, 169.0f / 255.0f, 122.0f / 255.0f, 1.0f); // Tan
	inline ImVec4 package_color = ImVec4(87.0f / 255.0f, 47.0f / 255.0f, 24.0f / 255.0f, 1.0f); // Brown
	inline ImVec4 sample_color = ImVec4(92.0f / 255.0f, 6.0f / 255.0f, 191.0f / 255.0f, 1.0f); // Purple

	inline bool secondary_item_state = false;
	inline bool secondary_distance = false;
	inline bool secondary_object_esp = true;
	inline bool secondary_radar = false;
	inline ImVec4 fuse_color = ImVec4(105.0f / 255.0f, 105.0f / 255.0f, 105.0f / 255.0f, 1.0f); // Grey
	inline ImVec4 battery_color = ImVec4(189.0f / 255.0f, 189.0f / 255.0f, 189.0f / 255.0f, 1.0f); // Light Grey
	inline ImVec4 screw_driver_color = ImVec4(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f, 1.0f); // White
	inline ImVec4 container_color = ImVec4(136.0f / 255.0f, 0.0f / 255.0f, 145.0f / 255.0f, 1.0f); // Magenta

	inline bool task_object_esp = true;
	inline bool task_object_distance = true;
	inline bool task_object_state = true;

	inline bool task_delivery = true;
	inline ImVec4 task_delivery_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow

	inline bool task_machine = true;
	inline ImVec4 task_machine_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow

	inline bool task_vent = true;
	inline ImVec4 task_vent_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow

	inline bool task_alim = true;
	inline ImVec4 task_alim_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow

	inline bool task_pizzushi = true;
	inline ImVec4 task_pizzushi_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow

	inline bool task_computers = true;
	inline ImVec4 task_computer_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow

	// Function to convert ImVec4 to JSON and vice versa
	inline void to_json(nlohmann::json& j, const ImVec4& color) {
		j = nlohmann::json{ {"r", color.x}, {"g", color.y}, {"b", color.z}, {"a", color.w} };
	}

	inline void from_json(const nlohmann::json& j, ImVec4& color) {
		j.at("r").get_to(color.x);
		j.at("g").get_to(color.y);
		j.at("b").get_to(color.z);
		j.at("a").get_to(color.w);
	}

	// Function to save config values to a JSON file
	inline void SaveConfig(const std::string& filename = "config.json") {
		std::string directory = "config";
		std::filesystem::create_directories(directory);  // Creates directory if it doesn't exist

		// Construct the full path to the config file
		std::string filePath = directory + "/" + filename;

		nlohmann::json j;
		// Save hotkey settings
		j["menu_hotkey"] = menu_hotkey;
		j["esp_hotkey"] = esp_hotkey;
		j["speedhack_hotkey"] = speedhack_hotkey;
		j["god_mode_hotkey"] = god_mode_hotkey;
		j["infinite_stamina_hotkey"] = infinite_stamina_hotkey;
		j["fast_melee_hotkey"] = fast_melee_hotkey;
		j["infinite_melee_range_hotkey"] = infinite_melee_range_hotkey;
		j["auto_fire_hotkey"] = auto_fire_hotkey;
		j["rapid_fire_hotkey"] = rapid_fire_hotkey;
		j["no_recoil_hotkey"] = no_recoil_hotkey;
		j["max_damage_hotkey"] = max_damage_hotkey;
		j["aimbot_hotkey"] = aimbot_hotkey;
		
		// Save boolean settings
		j["speedhack"] = speedhack;
		j["max_speed"] = max_speed;
		j["friction"] = friction;
		j["infinite_stamina"] = infinite_stamina;
		j["god_mode"] = god_mode;
		j["fast_melee"] = fast_melee;
		j["cast_time"] = cast_time;
		j["recover_time"] = recover_time;
		j["stun"] = stun;
		j["cost"] = cost;
		j["infinite_melee_range"] = infinite_melee_range;
		j["range"] = range;
		j["max_damage"] = max_damage;
		j["auto_fire"] = auto_fire;
		j["rapid_fire"] = rapid_fire;
		j["rapid_fire_rate"] = rapid_fire_rate;
		j["no_recoil"] = no_recoil;
		j["movement_osc"] = movement_osc;
		j["osc_reactivity"] = osc_reactivity;
		j["infinite_ammo"] = infinite_ammo;
		j["ammo_count"] = ammo_count;
		j["can_inventory"] = can_inventory;
		j["aimbot"] = aimbot;

		// Save ESP-related settings
		j["esp_enabled"] = esp_enabled;
		j["esp_max_distance"] = esp_max_distance;
		j["esp_radar"] = esp_radar;
		j["esp_radar_position"] = esp_radar_position;
		j["esp_radar_scale"] = esp_radar_scale;
		j["player_esp"] = player_esp;
		j["player_distance"] = player_distance;
		j["player_box"] = player_box;
		j["player_radar"] = player_radar;
		j["weapon_esp"] = weapon_esp;
		j["weapon_item_state"] = weapon_item_state;
		j["weapon_distance"] = weapon_distance;
		j["weapon_radar"] = weapon_radar;
		j["primary_object_esp"] = primary_object_esp;
		j["primary_item_state"] = primary_item_state;
		j["primary_distance"] = primary_distance;
		j["primary_radar"] = primary_radar;
		j["secondary_item_state"] = secondary_item_state;
		j["secondary_distance"] = secondary_distance;
		j["secondary_object_esp"] = secondary_object_esp;
		j["secondary_radar"] = secondary_radar;
		j["task_object_esp"] = task_object_esp;
		j["task_object_distance"] = task_object_distance;
		j["task_object_state"] = task_object_state;
		j["task_delivery"] = task_delivery;
		j["task_machine"] = task_machine;
		j["task_vent"] = task_vent;
		j["task_alim"] = task_alim;
		j["task_pizzushi"] = task_pizzushi;
		j["task_computers"] = task_computers;
		
		// Colors (individually serialize RGBA components for each color)
		j["employee_color"] = { {"r", employee_color.x}, {"g", employee_color.y}, {"b", employee_color.z}, {"a", employee_color.w} };
		j["dissident_color"] = { {"r", dissident_color.x}, {"g", dissident_color.y}, {"b", dissident_color.z}, {"a", dissident_color.w} };
		j["task_delivery_color"] = { {"r", task_delivery_color.x}, {"g", task_delivery_color.y}, {"b", task_delivery_color.z}, {"a", task_delivery_color.w} };
		j["task_machine_color"] = { {"r", task_machine_color.x}, {"g", task_machine_color.y}, {"b", task_machine_color.z}, {"a", task_machine_color.w} };
		j["task_vent_color"] = { {"r", task_vent_color.x}, {"g", task_vent_color.y}, {"b", task_vent_color.z}, {"a", task_vent_color.w} };
		j["task_alim_color"] = { {"r", task_alim_color.x}, {"g", task_alim_color.y}, {"b", task_alim_color.z}, {"a", task_alim_color.w} };
		j["task_pizzushi_color"] = { {"r", task_pizzushi_color.x}, {"g", task_pizzushi_color.y}, {"b", task_pizzushi_color.z}, {"a", task_pizzushi_color.w} };
		j["task_computer_color"] = { {"r", task_computer_color.x}, {"g", task_computer_color.y}, {"b", task_computer_color.z}, {"a", task_computer_color.w} };
		j["weapon_color"] = { {"r", weapon_color.x}, {"g", weapon_color.y}, {"b", weapon_color.z}, {"a", weapon_color.w} };
		j["fuse_color"] = { {"r", fuse_color.x}, {"g", fuse_color.y}, {"b", fuse_color.z}, {"a", fuse_color.w} };
		j["battery_color"] = { {"r", battery_color.x}, {"g", battery_color.y}, {"b", battery_color.z}, {"a", battery_color.w} };
		j["screw_driver_color"] = { {"r", screw_driver_color.x}, {"g", screw_driver_color.y}, {"b", screw_driver_color.z}, {"a", screw_driver_color.w} };
		j["container_color"] = { {"r", container_color.x}, {"g", container_color.y}, {"b", container_color.z}, {"a", container_color.w} };
		j["gaz_bottle_color"] = { {"r", gaz_bottle_color.x}, {"g", gaz_bottle_color.y}, {"b", gaz_bottle_color.z}, {"a", gaz_bottle_color.w} };
		j["vent_filter_color"] = { {"r", vent_filter_color.x}, {"g", vent_filter_color.y}, {"b", vent_filter_color.z}, {"a", vent_filter_color.w} };
		j["rice_color"] = { {"r", rice_color.x}, {"g", rice_color.y}, {"b", rice_color.z}, {"a", rice_color.w} };
		j["package_color"] = { {"r", package_color.x}, {"g", package_color.y}, {"b", package_color.z}, {"a", package_color.w} };
		j["sample_color"] = { {"r", sample_color.x}, {"g", sample_color.y}, {"b", sample_color.z}, {"a", sample_color.w} };
		
		std::ofstream file(filePath);  // This will create the file if it doesn't exist
		if (file.is_open()) {
			file << j.dump(4);  // Pretty print with 4 spaces
			file.close();
			std::cerr << "Config saved at " << filePath << std::endl;
		}
		else {
			std::cerr << "Error: Unable to open or create config file at " << filePath << std::endl;
		}
	}

	// Function to load config values from a JSON file
	inline void LoadConfig(const std::string& filename = "config.json") {
		std::string directory = "config";
		std::string filePath = directory + "/" + filename;
		std::ifstream file(filePath);
		if (!file.is_open()) {
			std::cerr << "Warning: Config file not found. Loading defaults." << std::endl;
			return;  // If file doesn't exist, load defaults and return
		}

		nlohmann::json j;
		file >> j;
		file.close();

		// Load hotkey settings
		j.at("menu_hotkey").get_to(menu_hotkey);
		j.at("esp_hotkey").get_to(esp_hotkey);
		j.at("speedhack_hotkey").get_to(speedhack_hotkey);
		j.at("god_mode_hotkey").get_to(god_mode_hotkey);
		j.at("infinite_stamina_hotkey").get_to(infinite_stamina_hotkey);
		j.at("fast_melee_hotkey").get_to(fast_melee_hotkey);
		j.at("infinite_melee_range_hotkey").get_to(infinite_melee_range_hotkey);
		j.at("auto_fire_hotkey").get_to(auto_fire_hotkey);
		j.at("rapid_fire_hotkey").get_to(rapid_fire_hotkey);
		j.at("no_recoil_hotkey").get_to(no_recoil_hotkey);
		j.at("max_damage_hotkey").get_to(max_damage_hotkey);
		j.at("aimbot_hotkey").get_to(aimbot_hotkey);

		// Load boolean settings
		j.at("speedhack").get_to(speedhack);
		j.at("max_speed").get_to(max_speed);
		j.at("friction").get_to(friction);
		j.at("infinite_stamina").get_to(infinite_stamina);
		j.at("god_mode").get_to(god_mode);
		j.at("fast_melee").get_to(fast_melee);
		j.at("cast_time").get_to(cast_time);
		j.at("recover_time").get_to(recover_time);
		j.at("stun").get_to(stun);
		j.at("cost").get_to(cost);
		j.at("infinite_melee_range").get_to(infinite_melee_range);
		j.at("range").get_to(range);
		j.at("max_damage").get_to(max_damage);
		j.at("auto_fire").get_to(auto_fire);
		j.at("rapid_fire").get_to(rapid_fire);
		j.at("rapid_fire_rate").get_to(rapid_fire_rate);
		j.at("no_recoil").get_to(no_recoil);
		j.at("movement_osc").get_to(movement_osc);
		j.at("osc_reactivity").get_to(osc_reactivity);
		j.at("infinite_ammo").get_to(infinite_ammo);
		j.at("ammo_count").get_to(ammo_count);
		j.at("can_inventory").get_to(can_inventory);
		j.at("aimbot").get_to(aimbot);

		// Load ESP-related settings
		j.at("esp_enabled").get_to(esp_enabled);
		j.at("esp_max_distance").get_to(esp_max_distance);
		j.at("esp_radar").get_to(esp_radar);
		j.at("esp_radar_position").get_to(esp_radar_position);
		j.at("esp_radar_scale").get_to(esp_radar_scale);
		j.at("player_esp").get_to(player_esp);
		j.at("player_distance").get_to(player_distance);
		j.at("player_box").get_to(player_box);
		j.at("player_radar").get_to(player_radar);
		j.at("weapon_esp").get_to(weapon_esp);
		j.at("weapon_item_state").get_to(weapon_item_state);
		j.at("weapon_distance").get_to(weapon_distance);
		j.at("weapon_radar").get_to(weapon_radar);
		j.at("primary_object_esp").get_to(primary_object_esp);
		j.at("primary_item_state").get_to(primary_item_state);
		j.at("primary_distance").get_to(primary_distance);
		j.at("primary_radar").get_to(primary_radar);
		j.at("secondary_item_state").get_to(secondary_item_state);
		j.at("secondary_distance").get_to(secondary_distance);
		j.at("secondary_object_esp").get_to(secondary_object_esp);
		j.at("secondary_radar").get_to(secondary_radar);
		j.at("task_object_esp").get_to(task_object_esp);
		j.at("task_object_distance").get_to(task_object_distance);
		j.at("task_object_state").get_to(task_object_state);
		j.at("task_delivery").get_to(task_delivery);
		j.at("task_machine").get_to(task_machine);
		j.at("task_vent").get_to(task_vent);
		j.at("task_alim").get_to(task_alim);
		j.at("task_pizzushi").get_to(task_pizzushi);
		j.at("task_computers").get_to(task_computers);

		// Colors (individually unpack RGBA components for each color if present)
		if (j.contains("employee_color")) {
			employee_color.x = j["employee_color"].at("r").get<float>();
			employee_color.y = j["employee_color"].at("g").get<float>();
			employee_color.z = j["employee_color"].at("b").get<float>();
			employee_color.w = j["employee_color"].at("a").get<float>();
		}

		if (j.contains("dissident_color")) {
			dissident_color.x = j["dissident_color"].at("r").get<float>();
			dissident_color.y = j["dissident_color"].at("g").get<float>();
			dissident_color.z = j["dissident_color"].at("b").get<float>();
			dissident_color.w = j["dissident_color"].at("a").get<float>();
		}

		if (j.contains("task_delivery_color")) {
			task_delivery_color.x = j["task_delivery_color"].at("r").get<float>();
			task_delivery_color.y = j["task_delivery_color"].at("g").get<float>();
			task_delivery_color.z = j["task_delivery_color"].at("b").get<float>();
			task_delivery_color.w = j["task_delivery_color"].at("a").get<float>();
		}

		if (j.contains("task_machine_color")) {
			task_machine_color.x = j["task_machine_color"].at("r").get<float>();
			task_machine_color.y = j["task_machine_color"].at("g").get<float>();
			task_machine_color.z = j["task_machine_color"].at("b").get<float>();
			task_machine_color.w = j["task_machine_color"].at("a").get<float>();
		}

		if (j.contains("task_vent_color")) {
			task_vent_color.x = j["task_vent_color"].at("r").get<float>();
			task_vent_color.y = j["task_vent_color"].at("g").get<float>();
			task_vent_color.z = j["task_vent_color"].at("b").get<float>();
			task_vent_color.w = j["task_vent_color"].at("a").get<float>();
		}

		if (j.contains("task_alim_color")) {
			task_alim_color.x = j["task_alim_color"].at("r").get<float>();
			task_alim_color.y = j["task_alim_color"].at("g").get<float>();
			task_alim_color.z = j["task_alim_color"].at("b").get<float>();
			task_alim_color.w = j["task_alim_color"].at("a").get<float>();
		}

		if (j.contains("task_pizzushi_color")) {
			task_pizzushi_color.x = j["task_pizzushi_color"].at("r").get<float>();
			task_pizzushi_color.y = j["task_pizzushi_color"].at("g").get<float>();
			task_pizzushi_color.z = j["task_pizzushi_color"].at("b").get<float>();
			task_pizzushi_color.w = j["task_pizzushi_color"].at("a").get<float>();
		}

		if (j.contains("task_computer_color")) {
			task_computer_color.x = j["task_computer_color"].at("r").get<float>();
			task_computer_color.y = j["task_computer_color"].at("g").get<float>();
			task_computer_color.z = j["task_computer_color"].at("b").get<float>();
			task_computer_color.w = j["task_computer_color"].at("a").get<float>();
		}

		if (j.contains("weapon_color")) {
			weapon_color.x = j["weapon_color"].at("r").get<float>();
			weapon_color.y = j["weapon_color"].at("g").get<float>();
			weapon_color.z = j["weapon_color"].at("b").get<float>();
			weapon_color.w = j["weapon_color"].at("a").get<float>();
		}

		if (j.contains("fuse_color")) {
			fuse_color.x = j["fuse_color"].at("r").get<float>();
			fuse_color.y = j["fuse_color"].at("g").get<float>();
			fuse_color.z = j["fuse_color"].at("b").get<float>();
			fuse_color.w = j["fuse_color"].at("a").get<float>();
		}

		if (j.contains("battery_color")) {
			battery_color.x = j["battery_color"].at("r").get<float>();
			battery_color.y = j["battery_color"].at("g").get<float>();
			battery_color.z = j["battery_color"].at("b").get<float>();
			battery_color.w = j["battery_color"].at("a").get<float>();
		}

		if (j.contains("screw_driver_color")) {
			screw_driver_color.x = j["screw_driver_color"].at("r").get<float>();
			screw_driver_color.y = j["screw_driver_color"].at("g").get<float>();
			screw_driver_color.z = j["screw_driver_color"].at("b").get<float>();
			screw_driver_color.w = j["screw_driver_color"].at("a").get<float>();
		}

		if (j.contains("container_color")) {
			container_color.x = j["container_color"].at("r").get<float>();
			container_color.y = j["container_color"].at("g").get<float>();
			container_color.z = j["container_color"].at("b").get<float>();
			container_color.w = j["container_color"].at("a").get<float>();
		}

		if (j.contains("gaz_bottle_color")) {
			gaz_bottle_color.x = j["gaz_bottle_color"].at("r").get<float>();
			gaz_bottle_color.y = j["gaz_bottle_color"].at("g").get<float>();
			gaz_bottle_color.z = j["gaz_bottle_color"].at("b").get<float>();
			gaz_bottle_color.w = j["gaz_bottle_color"].at("a").get<float>();
		}

		if (j.contains("vent_filter_color")) {
			vent_filter_color.x = j["vent_filter_color"].at("r").get<float>();
			vent_filter_color.y = j["vent_filter_color"].at("g").get<float>();
			vent_filter_color.z = j["vent_filter_color"].at("b").get<float>();
			vent_filter_color.w = j["vent_filter_color"].at("a").get<float>();
		}

		if (j.contains("rice_color")) {
			rice_color.x = j["rice_color"].at("r").get<float>();
			rice_color.y = j["rice_color"].at("g").get<float>();
			rice_color.z = j["rice_color"].at("b").get<float>();
			rice_color.w = j["rice_color"].at("a").get<float>();
		}

		if (j.contains("package_color")) {
			package_color.x = j["package_color"].at("r").get<float>();
			package_color.y = j["package_color"].at("g").get<float>();
			package_color.z = j["package_color"].at("b").get<float>();
			package_color.w = j["package_color"].at("a").get<float>();
		}

		if (j.contains("sample_color")) {
			sample_color.x = j["sample_color"].at("r").get<float>();
			sample_color.y = j["sample_color"].at("g").get<float>();
			sample_color.z = j["sample_color"].at("b").get<float>();
			sample_color.w = j["sample_color"].at("a").get<float>();
		}

		std::cerr << "Config loaded." << std::endl;
	}
}