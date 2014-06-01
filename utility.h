#pragma once
#include <math.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include "settings.h"

// ������� �� ������ � �������������� ���������� ��������
int mod_custom(int num, int max);

// ����������� ����� ����� �� ������ 0
int _0(const int x);

// �������� ����������� ����� �� ������ 0 � �������������� abs
int _0ia(const int x);

double round(double number);

void switch_flag(unsigned char& flags, unsigned int flag);

void draw_auxilliary_data(cv::Mat&,
						  const SteadySettings&,
						  const double&,
						  const double&,
						  const cv::Size&,
						  const cv::Point2d&);