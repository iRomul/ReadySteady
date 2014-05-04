#pragma once
#include <opencv2/imgproc/imgproc.hpp>

class ImageDevice {

	cv::Mat image;
	cv::Mat window;
	cv::Size window_size;
	cv::Point2d window_coord;
	bool everything_right;
	//��������� �������� ����
	void move_horizontal_right(unsigned range); //�������� �����-����� ������ �� ��������� �����

public:

	//������������
	ImageDevice();
	ImageDevice(char* , cv::Size); //����������� � ������� open(...) � set_window_size()
	//������� ���������
	void open(char* ); //��������� ����������� �� ����
	void set_window_size(cv::Size); //���������� ������� ����
	void set_base_coord(cv::Point2d);
	//������ �� ����������
	bool is_opened(); //�� �� ������
	ImageDevice& operator>>(cv::Mat&); //�������� ������� ����
	cv::Size set_window_size(); //�������� �������

};