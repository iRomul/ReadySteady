#pragma once
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

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