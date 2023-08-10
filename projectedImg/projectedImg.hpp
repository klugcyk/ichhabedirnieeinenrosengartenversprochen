/*
    文件等级：密一
    author:klug
    献给我的心上人等待天使的妹妹
    start:230810
    last:230810
*/

#ifndef projectedImg_HPP
#define projectedImg_HPP

#include <opencv2/opencv.hpp>
#include "math/geometry.hpp"

namespace projectImg
{

// 生成投射用的图像
class geneProjectImg
{
public:
    //functions
    geneProjectImg();
    ~geneProjectImg();

public:
    //variable
    cv::Mat projectedImg;
    cv::Mat reprojectedImg;
    mathGeometry::point2 projectLocation;

protected:
    //functions

    //variable

private:
    //functions

    //variable

};

};

#endif // zwei_phase_cal_HPP
