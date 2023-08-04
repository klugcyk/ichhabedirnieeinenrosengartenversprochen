/*
    文件等级：密一
    author:klug
    献给不喜欢我的弗里德里希冯海因洛特
    start:230706
    last:230801
*/

#ifndef zwei_phase_cal_HPP
#define zwei_phase_cal_HPP

#include <opencv2/opencv.hpp>
#include "cameraGene/cameraGene.hpp"
#include "source.hpp"

#define zweiPhaseCalPrintMsgInfo
#define zweiPhaseCalPrintErrorInfo
#define zweiPhaseCalPrintDataInfo

namespace zweiPhase
{

class zweiPhaseCal:public cameraGene
{
public:
    //functions
    zweiPhaseCal();
    ~zweiPhaseCal();

    //variable

protected:
    //functions
    int systemCalibrate(std::vector<cv::Mat> imgLink,std::vector<cv::Mat> imgRicht);

    //variable

private:
    //functions

    //variable

};

};

#endif // zwei_phase_cal_HPP
