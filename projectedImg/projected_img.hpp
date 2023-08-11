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

#define longitudinal 1 //纵向
#define transverse 0 //横向

#define geneProjectImgSave
#define geneProjectImgPrintError
#define geneProjectImgPrintMsg
#define geneProjectImgPrintData

namespace projectImg
{

// 生成投射用的图像
class geneProjectImg
{
public:
    //functions
    geneProjectImg();
    ~geneProjectImg();
    void cosImg(int row,int col,int waveLength=10,bool type=0);
    void sinImg(int row,int col,int waveLength=10,bool type=0);
    void cosImg4PhaseShift(int row,int col,int waveLength=10,bool type=0,int shift=0);
    void sinImg4PhaseShift(int row,int col,int waveLength=10,bool type=0,int shift=0);
    void lineImg(int row,int col,int waveLength=10,bool type=0);

public:
    //variables
    cv::Mat projectedImg;
    cv::Mat reprojectedImg;
    mathGeometry::point2 projectLocation;

};

};

#endif // zwei_phase_cal_HPP
