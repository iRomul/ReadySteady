#include "algos.h"
#include "utility.h"
#include <cmath>

// ������������, ���������� �� ������� ����������


Point2d calculate_offset_phase(Mat one, Mat two) {

	cvtColor(one, one, CV_BGR2GRAY);
	cvtColor(two, two, CV_BGR2GRAY);
	one.convertTo(one, CV_64F);
	two.convertTo(two, CV_64F);
	return phaseCorrelate(one, two);

}


Point2d calculate_offset_phase_optimized_multiscale(Mat one, Mat& two) {

	Mat one_scaled, two_scaled;

	double scale_size = 1;

	resize(one, one_scaled, Size(), scale_size, scale_size, INTER_NEAREST);
	resize(two, two_scaled, Size(), scale_size, scale_size, INTER_NEAREST);

	if(two_scaled.type() != CV_64F) {
		cvtColor(two_scaled, two_scaled, CV_BGR2GRAY);
		two_scaled.convertTo(two_scaled, CV_64F);
	}

	cvtColor(one_scaled, one_scaled, CV_BGR2GRAY);
	one_scaled.convertTo(one_scaled, CV_64F);
	
	Point2d half_coord = phaseCorrelate(one_scaled, two_scaled);

	return Point2d(half_coord.x * scale_size, half_coord.y * scale_size);
	
}

void move_image_roi_alt(Mat& img, Mat& trans, const Point2d& offset) {

	// TODO: Optimize

	trans = Mat::zeros(img.size(), img.type());
	img(
		Rect(
			_0(static_cast<int>(offset.x)),
			_0(static_cast<int>(offset.y)),
			img.cols-abs(static_cast<int>(offset.x)),
			img.rows-abs(static_cast<int>(offset.y))
		)
	).copyTo(trans(
		Rect(
			_0ia(static_cast<int>(offset.x)),
			_0ia(static_cast<int>(offset.y)),
			img.cols-abs(static_cast<int>(offset.x)), 
			img.rows-abs(static_cast<int>(offset.y))
		)	
	));

}