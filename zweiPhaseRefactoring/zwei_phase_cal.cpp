/*
    文件等级：密一
    author:klug
    献给不喜欢我的弗里德里希冯海因洛特
    start:230706
    last:230804
*/

#include "zweiPhaseRefactoring/zwei_phase_cal.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace zweiPhase
{

zweiPhaseCal::zweiPhaseCal()
{
    std::vector<cv::Mat> link,richt;

    for(int i=0;i<=zweiCalibrateImgNum;i++)
    {
        std::string readPath=imgPath;
        readPath+="zwei_construct/cal/link";
        readPath+=std::to_string(i);
        readPath+=".png";
        cv::Mat img=cv::imread(readPath);
        if(!img.empty())
        {
            link.push_back(img);
        }

        readPath=imgPath;
        readPath+="zwei_construct/cal/richt";
        readPath+=std::to_string(i);
        readPath+=".png";
        img=cv::imread(readPath);
        if(!img.empty())
        {
            richt.push_back(img);
        }
    }

    systemCalibrate(link,richt);
}

zweiPhaseCal::~zweiPhaseCal()
{

}

int zweiPhaseCal::systemCalibrate(std::vector<cv::Mat> imgLink,std::vector<cv::Mat> imgRicht)
{
    int res=zweiCameraCalibrate(imgLink,imgRicht);
    res=zweiCameraRectified();

    cv::Mat l,lr,r,rr,d;
    l=cv::imread("/home/klug/img/zwei_construct/link1.png");
    r=cv::imread("/home/klug/img/zwei_construct/richt1.png");

    cv::remap(l,lr,map11,map12,cv::INTER_LINEAR);
    cv::remap(r,rr,map21,map22,cv::INTER_LINEAR);

    cv::hconcat(lr,rr,d);

    cv::imwrite("/home/klug/img/zwei_construct/linkr.png",lr);
    cv::imwrite("/home/klug/img/zwei_construct/richtr.png",rr);
    cv::imwrite("/home/klug/img/zwei_construct/d.png",d);

    return res;
}

};
