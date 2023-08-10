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

#define geneProjectImgSave

namespace projectImg
{

// 生成投射用的图像
class geneProjectImg
{
public:
    //functions
    geneProjectImg();
    ~geneProjectImg();
    void cosImg(int row,int col,int waveLength,bool type);
    void sinImg(int row,int col,int waveLength,bool type);

public:
    //variable
    cv::Mat projectedImg;
    cv::Mat reprojectedImg;
    mathGeometry::point2 projectLocation;

};

};

#endif // zwei_phase_cal_HPP
