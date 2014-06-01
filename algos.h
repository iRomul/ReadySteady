#pragma once
#include <opencv2/imgproc/imgproc.hpp>

#include "settings.h"

using namespace cv;

////		����� ��� ������ � �����������		////

// ����������� ������������, ���������� �� ������� ����������
class Stabilizer {

	Mat base_frame; // ������� ����
	Point2f prev_offset; // ���������� ���������� ��������
	Point2f offset; // ������� ���������� ��������
	SteadySettings* settings; // ��������� ���������
	bool state; // ��������/���������
	float inner_scale; // ��������������� ������ ������� ����������
	float frame_scale; // ��������������� ��������������� �����
	bool reset_base_frame; // ���� ������ �������� �����

public:
	Stabilizer();
	void set_settings(SteadySettings*);
	void stabilize(Mat& A);
	void shift_images();
	void calcutae_offset(Mat& A);
	void operator()(Mat& A);

};

////		��������� ���������� ��������		////

// ���������� �������� ����� ������������� ������� ������� ����������
Point2d calculate_offset_phase(Mat one, Mat two);

// ���������� �������� ����� ������������� ������� ������� ���������� � ������������
Point2d calculate_offset_phase_optimized(Mat one, Mat& two);

// ���������� �������� ����� ������������� ������� ������� ���������� � ������������ � �������������� ���������������������
Point2d calculate_offset_phase_optimized_multiscale(Mat one, Mat& two);

////		��������� �������		////

// �������� ����������� � ����������� ������� ����� � �������
void move_images_cycle_roll(Mat& one, Point2d offset);

// �������� ����������� � ������������� ROI � ���������������� �����������
void move_image_roi_alt(Mat& img, Mat& trans, const Point2d& offset);