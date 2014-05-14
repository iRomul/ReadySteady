#pragma once

#include <string>
#include <iostream>
#include <windows.h>

struct SteadySettings {

	// ����
	enum device_type {DEV_FILE, DEV_CAMERA};

	// ������
	SteadySettings();
	void load();
	void save();
	void show();
	void print();
	bool verify();

	// ����
	std::string path_to_file;
	int frame_scale;
	int device_id;
	int camera_offset_threshold;
	int camera_lowpass_filter_amount;
	int frame_skipping_threshold;
	device_type dev_type;
	std::string path_to_video;

};