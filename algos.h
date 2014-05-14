#pragma once
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

////		��������� ���������� ��������		////

// ���������� �������� ����� ������������� ������� ������� ����������
Point2d calculate_offset_phase(Mat one, Mat two);

////		��������� �������		////

// �������� ����������� � ����������� ������� ����� � �������
void move_images_cycle_roll(Mat& one, Point2d offset);