#include "opencv2/shape.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/core/utility.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int lowThreshold = 20;
int ratio = 3;
int kernel_size = 3;



static vector<Point> simpleContour( const Mat& currentQuery, int n=300 )
{
    vector<vector<Point> > _contoursQuery;
    vector <Point> contoursQuery;
    findContours(currentQuery, _contoursQuery, RETR_LIST, CHAIN_APPROX_NONE);
    for (size_t border=0; border<_contoursQuery.size(); border++)
    {
        for (size_t p=0; p<_contoursQuery[border].size(); p++)
        {
            contoursQuery.push_back( _contoursQuery[border][p] );
        }
    }

    // In case actual number of points is less than n
    int dummy=0;
    for (int add=(int)contoursQuery.size()-1; add<n; add++)
    {
        contoursQuery.push_back(contoursQuery[dummy++]); //adding dummy values
    }

    // Uniformly sampling
    random_shuffle(contoursQuery.begin(), contoursQuery.end());
    vector<Point> cont;
    for (int i=0; i<n; i++)
    {
        cont.push_back(contoursQuery[i]);
    }
    return cont;
}

vector<Point> detectCanny(cv::Mat src)
{


    	cv::Mat detected_edges, blured_image;
        /// Reduce noise with a kernel 3x3
        cv::blur( src, blured_image, cv::Size(4,4) );
        detected_edges = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);
	//imshow("canny",detected_edges);
	//waitKey();
	Size sz2Sh(300,300);
        Mat cannyToShow;
    	resize(detected_edges, cannyToShow, sz2Sh);
    	imshow("canny", cannyToShow);
    	vector<Point> cannyQuery = simpleContour(detected_edges);
    	return cannyQuery;
}


int main(int argc, char** argv)
{
    //string path = "/home/jsh/opencv-3.1/opencv-3.1.0/samples/data/shape_sample/";
    string path1="/home/jsh/work/test_sc/pic/rgbd-dataset/apple/apple_1/";
	string path2="/home/jsh/work/test_sc/pic/rgbd-dataset/apple/apple_2/";
	string path3="/home/jsh/work/test_sc/pic/rgbd-dataset/apple/apple_3/";
	string path4="/home/jsh/work/test_sc/pic/rgbd-dataset/apple/apple_4/";
	string path5="/home/jsh/work/test_sc/pic/rgbd-dataset/apple/apple_5/";

	string path6="/home/jsh/work/test_sc/pic/rgbd-dataset/ball/ball_1/";
	string path7="/home/jsh/work/test_sc/pic/rgbd-dataset/ball/ball_2/";
	string path8="/home/jsh/work/test_sc/pic/rgbd-dataset/ball/ball_3/";
	string path9="/home/jsh/work/test_sc/pic/rgbd-dataset/ball/ball_4/";
	string path10="/home/jsh/work/test_sc/pic/rgbd-dataset/ball/ball_5/";
	string path11="/home/jsh/work/test_sc/pic/rgbd-dataset/ball/ball_6/";
	string path12="/home/jsh/work/test_sc/pic/rgbd-dataset/ball/ball_7/";

	string path13="/home/jsh/work/test_sc/pic/rgbd-dataset/banana/banana_1/";
	string path14="/home/jsh/work/test_sc/pic/rgbd-dataset/banana/banana_2/";
	string path15="/home/jsh/work/test_sc/pic/rgbd-dataset/banana/banana_3/";
	string path16="/home/jsh/work/test_sc/pic/rgbd-dataset/banana/banana_4/";

	string path17="/home/jsh/work/test_sc/pic/rgbd-dataset/bell_pepper/bell_pepper_1/";
	string path18="/home/jsh/work/test_sc/pic/rgbd-dataset/bell_pepper/bell_pepper_2/";
	string path19="/home/jsh/work/test_sc/pic/rgbd-dataset/bell_pepper/bell_pepper_3/";
	string path20="/home/jsh/work/test_sc/pic/rgbd-dataset/bell_pepper/bell_pepper_4/";
	string path21="/home/jsh/work/test_sc/pic/rgbd-dataset/bell_pepper/bell_pepper_5/";
	string path22="/home/jsh/work/test_sc/pic/rgbd-dataset/bell_pepper/bell_pepper_6/";

	string path23="/home/jsh/work/test_sc/pic/rgbd-dataset/binder/binder_1/";
	string path24="/home/jsh/work/test_sc/pic/rgbd-dataset/binder/binder_2/";
	string path25="/home/jsh/work/test_sc/pic/rgbd-dataset/binder/binder_3/";

	string path26="/home/jsh/work/test_sc/pic/rgbd-dataset/bowl/bowl_1/";
	string path27="/home/jsh/work/test_sc/pic/rgbd-dataset/bowl/bowl_2/";
	string path28="/home/jsh/work/test_sc/pic/rgbd-dataset/bowl/bowl_3/";
	string path29="/home/jsh/work/test_sc/pic/rgbd-dataset/bowl/bowl_4/";
	string path30="/home/jsh/work/test_sc/pic/rgbd-dataset/bowl/bowl_5/";
	string path31="/home/jsh/work/test_sc/pic/rgbd-dataset/bowl/bowl_6/";

	string path32="/home/jsh/work/test_sc/pic/rgbd-dataset/calculator/calculator_1/";
	string path33="/home/jsh/work/test_sc/pic/rgbd-dataset/calculator/calculator_2/";
	string path34="/home/jsh/work/test_sc/pic/rgbd-dataset/calculator/calculator_3/";
	string path35="/home/jsh/work/test_sc/pic/rgbd-dataset/calculator/calculator_4/";
	string path36="/home/jsh/work/test_sc/pic/rgbd-dataset/calculator/calculator_5/";

	string path37="/home/jsh/work/test_sc/pic/rgbd-dataset/camera/camera_1/";
	string path38="/home/jsh/work/test_sc/pic/rgbd-dataset/camera/camera_2/";
	string path39="/home/jsh/work/test_sc/pic/rgbd-dataset/camera/camera_3/";

	string path40="/home/jsh/work/test_sc/pic/rgbd-dataset/cap/cap_1/";
	string path41="/home/jsh/work/test_sc/pic/rgbd-dataset/cap/cap_2/";
	string path42="/home/jsh/work/test_sc/pic/rgbd-dataset/cap/cap_3/";
	string path43="/home/jsh/work/test_sc/pic/rgbd-dataset/cap/cap_4/";

	string path44="/home/jsh/work/test_sc/pic/rgbd-dataset/cell_phone/cell_phone_1/";
	string path45="/home/jsh/work/test_sc/pic/rgbd-dataset/cell_phone/cell_phone_2/";
	string path46="/home/jsh/work/test_sc/pic/rgbd-dataset/cell_phone/cell_phone_3/";
	string path47="/home/jsh/work/test_sc/pic/rgbd-dataset/cell_phone/cell_phone_4/";
	string path48="/home/jsh/work/test_sc/pic/rgbd-dataset/cell_phone/cell_phone_5/";

    /*int indexQuery = parser.get<int>("@input");
    if (!parser.check())
    {
        parser.printErrors();
        help();
        return 1;
    }
    if (indexQuery < 1 || indexQuery > 20)
    {
        help();
        return 1;
    }*/
    cv::Ptr <cv::ShapeContextDistanceExtractor> mysc = cv::createShapeContextDistanceExtractor();

    Size sz2Sh(300,300);
    //stringstream queryName;
    //queryName<<path<<indexQuery<<".png";
    //Mat query=imread(queryName.str(), IMREAD_GRAYSCALE);

    //Mat query1=imread("apple_1_1_1_crop.png");
    //imshow("Object",query1);
    //waitKey();
    Mat query1=imread(argv[1]);
    vector<Point> contQuery1=detectCanny(query1);

    Mat queryToShow;
    resize(query1, queryToShow, sz2Sh);
    imshow("QUERY", queryToShow);
    waitKey(30);
    //destroyWindow("QUERY");
    
    float avg[10];
    moveWindow("TEST", 0,0);
    //vector<Point> contQuery = simpleContour(query);
    int bestMatch = 0;
    float bestDis=FLT_MAX;
    float Dis1[19];
    int j1=0;
    for ( int ii=1; ii<=10; ii++ )
    {
        //if (ii==indexQuery) continue;
        int m=ii*19;
        //waitKey(30);
        stringstream iiname;
        iiname<<path1<<"apple_1_1_"<<m<<"_crop"<<".png";
        //cout<<"name: "<<iiname.str()<<endl;
        Mat iiIm=imread(iiname.str(), 0);
        Mat iiToShow;

		Mat detected_edges1, blured_image1;
        /// Reduce noise with a kernel 3x3
        blur( iiIm, blured_image1, cv::Size(4,4) );
        detected_edges1 = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image1, detected_edges1, lowThreshold, lowThreshold*ratio, kernel_size);

        resize(detected_edges1, iiToShow, sz2Sh);
        //imshow("TEST", iiToShow);
	//vector<Point> contii=detectCanny(iiIm);
        moveWindow("TEST", sz2Sh.width+50,0);
        vector<Point> contii = simpleContour(detected_edges1);
        float dis = mysc->computeDistance( contQuery1, contii );
        if(j1==0)
        {
        	Dis1[0]=dis;
        	j1++;	
        }
        else
        {
        	if(dis<(10*Dis1[j1-1])) 
        	{
        		Dis1[j1]=dis;
        		j1++;
        	}
        }
        
        if ( dis<bestDis )
        {
            bestMatch = m;
            bestDis = dis;
        }
        //std::cout<<" distance between "<<iiname.str()<<" is: "<<dis<<std::endl;
        //i1+10;
    }
    std::cout<<"processing 1/10"<<endl;

    float sum1=0;
    for(int m=0;m<j1;m++)
    {
    	sum1=sum1+Dis1[m];
    }
    float avg1=sum1/j1;
    avg[0]=avg1;
    //cout<<"!"<<avg1<<endl;
    
    float Dis2[19];
    int j2=0;
    for ( int ii=1; ii<=10; ii++ )
    {
        //if (ii==indexQuery) continue;
        float avg=0;
        int m=ii*19;
        //waitKey(30);
        stringstream iiname;
        iiname<<path6<<"ball_1_1_"<<m<<"_crop"<<".png";
        //cout<<"name: "<<iiname.str()<<endl;
        Mat iiIm=imread(iiname.str(), 0);
        Mat iiToShow;

		Mat detected_edges1, blured_image1;
        /// Reduce noise with a kernel 3x3
        blur( iiIm, blured_image1, cv::Size(4,4) );
        detected_edges1 = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image1, detected_edges1, lowThreshold, lowThreshold*ratio, kernel_size);

        resize(detected_edges1, iiToShow, sz2Sh);
        //imshow("TEST", iiToShow);
	//vector<Point> contii=detectCanny(iiIm);
        moveWindow("TEST", sz2Sh.width+50,0);
        vector<Point> contii = simpleContour(detected_edges1);
        float dis = mysc->computeDistance( contQuery1, contii );
        if(j2==0)
        {
        	Dis2[0]=dis;
        	j2++;	
        }
        else
        {
        	if(dis<(10*Dis2[j2-1])) 
        	{
        		Dis2[j2]=dis;
        		j2++;
        	}
        }

        if ( dis<bestDis )
        {
            bestMatch = m;
            bestDis = dis;
        }
        //std::cout<<" distance between "<<iiname.str()<<" is: "<<dis<<std::endl;
    }
    float sum2=0;
    for(int m=0;m<j2;m++)
    {
    	sum2=sum2+Dis2[m];
    }
    float avg2=sum2/j2;
    avg[1]=avg2;
    //cout<<"!"<<avg2<<endl;
    std::cout<<"processing 2/10"<<endl;

    float Dis3[19];
    int j3=0;
    for ( int ii=1; ii<=10; ii++ )
    {
        //if (ii==indexQuery) continue;
        int m=ii*19;
        float avg=0;

        //waitKey(30);
        stringstream iiname;
        iiname<<path13<<"banana_1_1_"<<m<<"_crop"<<".png";
        //cout<<"name: "<<iiname.str()<<endl;
        Mat iiIm=imread(iiname.str(), 0);
        Mat iiToShow;

		Mat detected_edges1, blured_image1;
        /// Reduce noise with a kernel 3x3
        blur( iiIm, blured_image1, cv::Size(4,4) );
        detected_edges1 = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image1, detected_edges1, lowThreshold, lowThreshold*ratio, kernel_size);

        resize(detected_edges1, iiToShow, sz2Sh);
        //imshow("TEST", iiToShow);
	//vector<Point> contii=detectCanny(iiIm);
        moveWindow("TEST", sz2Sh.width+50,0);
        vector<Point> contii = simpleContour(detected_edges1);
        float dis = mysc->computeDistance( contQuery1, contii );
        if(j3==0)
        {
        	Dis3[0]=dis;
        	j3++;	
        }
        else
        {
        	if(dis<(10*Dis3[j3-1])) 
        	{
        		Dis3[j3]=dis;
        		j3++;
        	}
        }
        if ( dis<bestDis )
        {
            bestMatch = m;
            bestDis = dis;
        }
        //std::cout<<" distance between "<<iiname.str()<<" is: "<<dis<<std::endl;
    }
    float sum3=0;
    for(int m=0;m<j3;m++)
    {
    	sum3=sum3+Dis3[m];
    }
    float avg3=sum3/j3;
    avg[2]=avg3;
    //cout<<"!"<<avg3<<endl;
    std::cout<<"processing 3/10"<<endl;

    float Dis4[19];
    int j4=0;
    for ( int ii=1; ii<=10; ii++ )
    {
        //if (ii==indexQuery) continue;
        int m=ii*19;
        float avg=0;

        //waitKey(30);
        stringstream iiname;
        iiname<<path17<<"bell_pepper_1_1_"<<m<<"_crop"<<".png";
        //cout<<"name: "<<iiname.str()<<endl;
        Mat iiIm=imread(iiname.str(), 0);
        Mat iiToShow;

		Mat detected_edges1, blured_image1;
        /// Reduce noise with a kernel 3x3
        blur( iiIm, blured_image1, cv::Size(4,4) );
        detected_edges1 = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image1, detected_edges1, lowThreshold, lowThreshold*ratio, kernel_size);

        resize(detected_edges1, iiToShow, sz2Sh);
        //imshow("TEST", iiToShow);
	//vector<Point> contii=detectCanny(iiIm);
        moveWindow("TEST", sz2Sh.width+50,0);
        vector<Point> contii = simpleContour(detected_edges1);
        float dis = mysc->computeDistance( contQuery1, contii );
        if(j4==0)
        {
        	Dis4[0]=dis;
        	j4++;	
        }
        else
        {
        	if(dis<(10*Dis4[j4-1])) 
        	{
        		Dis4[j4]=dis;
        		j4++;
        	}
        }
        if ( dis<bestDis )
        {
            bestMatch = m;
            bestDis = dis;
        }
        //std::cout<<" distance between "<<iiname.str()<<" is: "<<dis<<std::endl;
    }
    float sum4=0;
    for(int m=0;m<j4;m++)
    {
    	sum4=sum4+Dis4[m];
    }
    float avg4=sum4/j4;
    avg[3]=avg4;
    //cout<<"!"<<avg4<<endl;
    std::cout<<"processing 4/10"<<endl;

    float Dis5[19];
    int j5=0;
    for ( int ii=1; ii<=10; ii++ )
    {
        //if (ii==indexQuery) continue;
        int m=ii*19;
        float avg=0;

        //waitKey(30);
        stringstream iiname;
        iiname<<path23<<"binder_1_1_"<<m<<"_crop"<<".png";
        //cout<<"name: "<<iiname.str()<<endl;
        Mat iiIm=imread(iiname.str(), 0);
        Mat iiToShow;

		Mat detected_edges1, blured_image1;
        /// Reduce noise with a kernel 3x3
        blur( iiIm, blured_image1, cv::Size(4,4) );
        detected_edges1 = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image1, detected_edges1, lowThreshold, lowThreshold*ratio, kernel_size);

        resize(detected_edges1, iiToShow, sz2Sh);
        //imshow("TEST", iiToShow);
		//vector<Point> contii=detectCanny(iiIm);
        moveWindow("TEST", sz2Sh.width+50,0);
        vector<Point> contii = simpleContour(detected_edges1);
        float dis = mysc->computeDistance( contQuery1, contii );
        if(j5==0)
        {
        	Dis5[0]=dis;
        	j5++;	
        }
        else
        {
        	if(dis<(10*Dis5[j5-1])) 
        	{
        		Dis5[j5]=dis;
        		j5++;
        	}
        }
        if ( dis<bestDis )
        {
            bestMatch = m;
            bestDis = dis;
        }
        //std::cout<<" distance between "<<iiname.str()<<" is: "<<dis<<std::endl;
    }
    float sum5=0;
    for(int m=0;m<j5;m++)
    {
    	sum5=sum5+Dis5[m];
    }
    float avg5=sum5/j5;
    avg[4]=avg5;
    //cout<<"!"<<avg5<<endl;
    std::cout<<"processing 5/10"<<endl;

    float Dis6[19];
    int j6=0;
    for ( int ii=1; ii<=10 ;ii++ )
    {
        //if (ii==indexQuery) continue;
        int m=ii*18;
        float avg=0;

        //waitKey(30);
        stringstream iiname;
        iiname<<path26<<"bowl_1_1_"<<m<<"_crop"<<".png";
        //cout<<"name: "<<iiname.str()<<endl;
        Mat iiIm=imread(iiname.str(), 0);
        Mat iiToShow;

		Mat detected_edges1, blured_image1;
        /// Reduce noise with a kernel 3x3
        blur( iiIm, blured_image1, cv::Size(4,4) );
        detected_edges1 = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image1, detected_edges1, lowThreshold, lowThreshold*ratio, kernel_size);

        resize(detected_edges1, iiToShow, sz2Sh);
        //imshow("TEST", iiToShow);
	//vector<Point> contii=detectCanny(iiIm);
        moveWindow("TEST", sz2Sh.width+50,0);
        vector<Point> contii = simpleContour(detected_edges1);
        float dis = mysc->computeDistance( contQuery1, contii );
        if(j6==0)
        {
        	Dis6[0]=dis;
        	j6++;	
        }
        else
        {
        	if(dis<(10*Dis6[j6-1])) 
        	{
        		Dis6[j6]=dis;
        		j6++;
        	}
        }
        if ( dis<bestDis )
        {
            bestMatch = m;
            bestDis = dis;
        }
        //std::cout<<" distance between "<<iiname.str()<<" is: "<<dis<<std::endl;
    }
    float sum6=0;
    for(int m=0;m<j6;m++)
    {
    	sum6=sum6+Dis6[m];
    }
    float avg6=sum6/j6;
    avg[5]=avg6;
    //cout<<"!"<<avg6<<endl;
    std::cout<<"processing 6/10"<<endl;

    float Dis7[19];
    int j7=0;
    for ( int ii=1; ii<=10; ii++ )
    {
        //if (ii==indexQuery) continue;
        int m=ii*19;
        float avg=0;

        //waitKey(30);
        stringstream iiname;
        iiname<<path32<<"calculator_1_1_"<<m<<"_crop"<<".png";
        //cout<<"name: "<<iiname.str()<<endl;
        Mat iiIm=imread(iiname.str(), 0);
        Mat iiToShow;

		Mat detected_edges1, blured_image1;
        /// Reduce noise with a kernel 3x3
        blur( iiIm, blured_image1, cv::Size(4,4) );
        detected_edges1 = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image1, detected_edges1, lowThreshold, lowThreshold*ratio, kernel_size);

        resize(detected_edges1, iiToShow, sz2Sh);
        //imshow("TEST", iiToShow);
	//vector<Point> contii=detectCanny(iiIm);
        moveWindow("TEST", sz2Sh.width+50,0);
        vector<Point> contii = simpleContour(detected_edges1);
        float dis = mysc->computeDistance( contQuery1, contii );
        if(j7==0)
        {
        	Dis7[0]=dis;
        	j7++;	
        }
        else
        {
        	if(dis<(10*Dis7[j7-1])) 
        	{
        		Dis7[j7]=dis;
        		j7++;
        	}
        }
        if ( dis<bestDis )
        {
            bestMatch = m;
            bestDis = dis;
        }
        //std::cout<<" distance between "<<iiname.str()<<" is: "<<dis<<std::endl;
    }
    float sum7=0;
    for(int m=0;m<j7;m++)
    {
    	sum7=sum7+Dis7[m];
    }
    float avg7=sum7/j7;
    avg[6]=avg7;
    //cout<<"!"<<avg7<<endl;
    std::cout<<"processing 7/10"<<endl;

    float Dis8[19];
    int j8=0;
    for ( int ii=1; ii<=10; ii++ )
    {
        //if (ii==indexQuery) continue;
        int m=ii*19;
        float avg=0;

        //waitKey(30);
        stringstream iiname;
        iiname<<path37<<"camera_1_1_"<<m<<"_crop"<<".png";
        //cout<<"name: "<<iiname.str()<<endl;
        Mat iiIm=imread(iiname.str(), 0);
        Mat iiToShow;

		Mat detected_edges1, blured_image1;
        /// Reduce noise with a kernel 3x3
        blur( iiIm, blured_image1, cv::Size(4,4) );
        detected_edges1 = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image1, detected_edges1, lowThreshold, lowThreshold*ratio, kernel_size);

        resize(detected_edges1, iiToShow, sz2Sh);
        //imshow("TEST", iiToShow);
	//vector<Point> contii=detectCanny(iiIm);
        moveWindow("TEST", sz2Sh.width+50,0);
        vector<Point> contii = simpleContour(detected_edges1);
        float dis = mysc->computeDistance( contQuery1, contii );
        if(j8==0)
        {
        	Dis8[0]=dis;
        	j8++;	
        }
        else
        {
        	if(dis<(10*Dis8[j8-1])) 
        	{
        		Dis8[j8]=dis;
        		j8++;
        	}
        }
        if ( dis<bestDis )
        {
            bestMatch = m;
            bestDis = dis;
        }
        //std::cout<<" distance between "<<iiname.str()<<" is: "<<dis<<std::endl;
    }
    float sum8=0;
    for(int m=0;m<j8;m++)
    {
    	sum8=sum8+Dis8[m];
    }
    float avg8=sum8/j8;
    avg[7]=avg8;
    //cout<<"!"<<avg8<<endl;
    std::cout<<"processing 8/10"<<endl;

    float Dis9[19];
    int j9=0;
    for ( int ii=1; ii<=10; ii++ )
    {
        //if (ii==indexQuery) continue;
        int m=ii*19;
        float avg=0;

        //waitKey(30);
        stringstream iiname;
        iiname<<path40<<"cap_1_1_"<<m<<"_crop"<<".png";
        //cout<<"name: "<<iiname.str()<<endl;
        Mat iiIm=imread(iiname.str(), 0);
        Mat iiToShow;

		Mat detected_edges1, blured_image1;
        /// Reduce noise with a kernel 3x3
        blur( iiIm, blured_image1, cv::Size(4,4) );
        detected_edges1 = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image1, detected_edges1, lowThreshold, lowThreshold*ratio, kernel_size);

        resize(detected_edges1, iiToShow, sz2Sh);
        //imshow("TEST", iiToShow);
	//vector<Point> contii=detectCanny(iiIm);
        moveWindow("TEST", sz2Sh.width+50,0);
        vector<Point> contii = simpleContour(detected_edges1);
        float dis = mysc->computeDistance( contQuery1, contii );
        if(j9==0)
        {
        	Dis9[0]=dis;
        	j9++;	
        }
        else
        {
        	if(dis<(10*Dis9[j9-1])) 
        	{
        		Dis9[j9]=dis;
        		j9++;
        	}
        }
        if ( dis<bestDis )
        {
            bestMatch = m;
            bestDis = dis;
        }
        //std::cout<<" distance between "<<iiname.str()<<" is: "<<dis<<std::endl;
    }
    float sum9=0;
    for(int m=0;m<j9;m++)
    {
    	sum9=sum9+Dis9[m];
    }
    float avg9=sum9/j9;
    avg[8]=avg9;
    //cout<<"!"<<avg9<<endl;
    std::cout<<"processing 9/10"<<endl;

    float Dis10[19];
    int j10=0;
    for ( int ii=1; ii<=10; ii++ )
    {
        //if (ii==indexQuery) continue;
        int m=ii*19;
        float avg=0;

        //waitKey(30);
        stringstream iiname;
        iiname<<path44<<"cell_phone_1_1_"<<m<<"_crop"<<".png";
        //cout<<"name: "<<iiname.str()<<endl;
        Mat iiIm=imread(iiname.str(), 0);
        Mat iiToShow;

		Mat detected_edges1, blured_image1;
        /// Reduce noise with a kernel 3x3
        blur( iiIm, blured_image1, cv::Size(4,4) );
        detected_edges1 = cv::Scalar::all(0);
        /// Canny detector
        cv::Canny( blured_image1, detected_edges1, lowThreshold, lowThreshold*ratio, kernel_size);

        resize(detected_edges1, iiToShow, sz2Sh);
        //imshow("TEST", iiToShow);
	//vector<Point> contii=detectCanny(iiIm);
        moveWindow("TEST", sz2Sh.width+50,0);
        vector<Point> contii = simpleContour(detected_edges1);
        float dis = mysc->computeDistance( contQuery1, contii );
        if(j10==0)
        {
        	Dis10[0]=dis;
        	j10++;	
        }
        else
        {
        	if(dis<(10*Dis10[j10-1])) 
        	{
        		Dis10[j10]=dis;
        		j10++;
        	}
        }
        if ( dis<bestDis )
        {
            bestMatch = m;
            bestDis = dis;
        }
        //std::cout<<" distance between "<<iiname.str()<<" is: "<<dis<<std::endl;
    }
    float sum10=0;
    for(int m=0;m<j10;m++)
    {
    	sum10=sum10+Dis10[m];
    }
    float avg10=sum10/j10;
    avg[9]=avg10;
    //cout<<"!"<<avg10<<endl;
    destroyWindow("TEST");

    float mini;
    int flag;
    for(int t=0;t<10;t++)
    {
    	//std::cout<<avg[t]<<endl;
    	if(t==0)
    	{
    		mini=avg[0];
    		flag=1;
    	}
    	
    	else
    	{
    		if(avg[t]<mini)
    			{
    				mini=avg[t];
    				flag=t+1;
    			}
    	}
    }
    std::cout<<"processing done!"<<endl;
    std::cout<<endl;
    std::cout<<endl;
    std::cout<<"It's ";
    //std::cout<<flag<<" "<<mini<<endl;

    switch(flag)
    {
    	case (1): std::cout<<"an apple"<<endl;
    				break;
    	case (2): std::cout<<"a ball"<<endl;
    				break;
    	case (3): std::cout<<"a banana"<<endl;
    				break;
    	case (4): std::cout<<"a bell_pepper"<<endl;
    				break;
    	case (5): std::cout<<"a binder"<<endl;
    				break;
    	case (6): std::cout<<"a bowl"<<endl;
    				break;
    	case (7): std::cout<<"a calculator"<<endl;
    				break;			
    	case (8): std::cout<<"a camera"<<endl;
    				break;				
    	case (9): std::cout<<"a cap"<<endl;
    				break;
    	case (10): std::cout<<"a cell_phone"<<endl;
    				break;
    }
    //stringstream bestname;
    //bestname<<path<<bestMatch<<".png";
   // Mat iiIm=imread(bestname.str(), 0);
    //Mat bestToShow;
    //resize(iiIm, bestToShow, sz2Sh);
    //imshow("BEST MATCH", bestToShow);
   // moveWindow("BEST MATCH", sz2Sh.width+50,0);

    return 0;
}

