#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "image_device.h"
#include <iostream>

using namespace std;
using namespace cv;

Point2d calculate_offset(Mat one, Mat two) {

	cvtColor(one, one, CV_BGR2GRAY);
	cvtColor(two, two, CV_BGR2GRAY);
	one.convertTo(one, CV_64FC1);
	two.convertTo(two, CV_64FC1);
	return phaseCorrelate(one, two);

}

int main() {

	//����������� ����������
	char* path_to_image = "C:\\Short\\Projects\\OFBench\\Media\\TestExampleTwo.jpg";
	Size frame_size(600, 600);
	ImageDevice imdev(path_to_image, frame_size);
	Mat current_frame; //������� ����
	Mat reference_frame; //������� ���� ��� �������
	Mat processed_frame(frame_size, CV_8UC3);

	//������� ���������
	int offset_threshold = 10; //����� �������� ��� �������

	//�������������� ����������
	bool use_last_frame = false; //���� ������������� ����������� ����� ��� �������
	Point2d offset(0, 0); //�������� ����� 2 �������������
	Rect cutter_frame; //������������� ��� ROI � ��������� ������������
	namedWindow("Ready"); //������
	namedWindow("Steady");
	namedWindow("Ref");

	while(true) {

		imdev >> current_frame; //�������� ����������� � ����������
		imshow("Ready", current_frame); //������� ���������� � ������������ ����

		//���� 1. ������
		//���� �� �����-�� ������� ���� �������, �� ���������� ����� ����������� �����������
		//������� ������:
		//	�������� ����������� ������ ��������� ������
		//	������� ������� ��������
		if(!use_last_frame) {
			reference_frame = current_frame;
			use_last_frame = true;
		}

		offset = calculate_offset(current_frame, reference_frame); //������������ �������� ����� �������������
		//���� �������� ������ ���������� �����...
		if(abs(offset.x) > offset_threshold || abs(offset.y) > offset_threshold) {

			//...������ ������ �������� � ����� � ��������� ����������� ���� ���������
			use_last_frame = false;

		} else {

			//� ��������� ������ �� ������� �������� �����������, ������������ �������� � voila!
			//��������, ����� ������ ���������� ����� ����
			if(offset.x >= 0 && offset.y >= 0) {
				//���������, �� ���������� �� ����������� ������� ������
				if(offset.x > current_frame.cols && offset.y > current_frame.rows)
					use_last_frame = false;
				else {
					processed_frame.adjustROI(offset.y, current_frame.rows, offset.x, current_frame.cols) = current_frame(Rect(0, 0, current_frame.cols-offset.x, current_frame.rows-offset.y));
				}
				
			}

		}
		
		imshow("Steady", processed_frame);
		imshow("Ref", reference_frame);

		char c = (char)waitKey(250);

		if(c == 'e' || c == '�') break; //���� ������ e, �� �������
		if(c == 'q' || c == '�') {--offset_threshold; cout << "Threshold " << offset_threshold << endl;}
		if(c == 'w' || c == '�') {++offset_threshold; cout << "Threshold " << offset_threshold << endl;}

	}

	return EXIT_SUCCESS;

}