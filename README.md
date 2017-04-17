# Our Project:2D And 3D Shape Recognition

Our Member:范江 蒋思宏 程彦军 唐鸣跃

Introduction:The goal of shape recognition is, given an image including 2D or 3D shaped object, to recognize whether the object has the same shape as shaped objects in a database. In this project, you need to have at least 10 different 2D shaped objects and 10 different 3D shaped objects in your database. Given a 2D image of a shaped object, your program should be able to automatically identify whether the shape of this object is defined in the database, if yes, what is the shape. Otherwise, return unrecognized shape

The fifth week, our group's main work is as follows:

1)Build a 2d and 3d shape database

2)Read the reference to know the method of shape recognition 

3)To design our shape recognition method


Reference:

1)Object Shape Recognition Using Wavelet Descriptors

2)Learning 2D Shape Models

Week 4 (3.6-3.12)

本周进度：

～下载课程网站上的project description，和youtube上的示例视频，了解关于2D and 3D shape recognition的相关内容。

～阅读了以下几篇关于shape recognition的survey。了解了shape recognition中使用的一些方法。
    [1]SVEN LONCARIC.A SURVEY OF SHAPE ANALYSIS TECHNIQUES.Pattern Recognition, Vol. 31, No. 8, pp. 983—1001, 1998
    [2]Ronen Basri a , Luiz Costa b , Davi Geiger c , David Jacobs.Determining the similarity of deformable shapes.Vision Research 38 (1998) 2365 – 2385
    [3]Richard J. Campbell and Patrick J. Flynn.A Survey Of Free-Form Object Representation and Recognition Techniques.Computer Vision and Image Understanding 81, 166–210 (2001)
    文献[1]主要介绍了形状分析中，形状表示和形状描述方面的一些技术与方法。形状表示方法用非数字的形式表示原始的形状，使得形状中的重要特征得以保存。而形状描述是指通过那些能够生成形状的数字描述子的方法，得到形状特征向量的过程。形状描述在形状分析流程上一般在形状表示之后。形状描述方法需要具备对 translation, scale, 和 rotation的不变性。形状匹配或区分其实就是形状之间的比较，它被用于基于模型的物品识别，其识别方式是通过将未知的形状与已知的形状模型数据集比较。因此需要运用形状描述方法对每个未知和已知的形状处理，得到相应的特征向量。文献介绍了Fourier transform of boundary、Bending energy、Stochastic methods、Arc height method等基于边缘尺度变换的方法，和Chain code、Syntactic techniques、Boundary approximations、Scale-space techniques、Boundary decomposition等基于边缘空间域的方法。以上两部分的方法都属于基于形状局部信息的方法，与之相对的是基于全局形状信息的方法，这一部分也分为基于尺度和基于空间的方法。前者包括Shape matrices and vectors、Morphological methods等，后者包括Medial axis transform、Shape decomposition等。文献[2]主要介绍了两点，一是哪些对人在形状相似度的判断十分重要的属性，二是研究了基于形状边缘局部比较的相似度能多大程度的获取这些属性。文献举了几个例子来展示局部结构在人类对相似度判断过程中的重要角色，并从形状边缘的物理模型中提出了3种新的代价函数。文献[3]的焦点在于三维物体模型的搭建和识别，介绍了一些从噪声中找到并识别物体的方法，包括Appearance-based Recognition、Recognition from 2D Silhouettes、Free-Form Object Recognition in Range Data。
 


Week 5 （3.13-3.19）

本周进度：

~阅读文献：[1]Belongie S, Malik J, Puzicha J. Shape Matching and Object Recognition Using Shape Contexts. IEEE Transactions on Pattern Analysis &  Machine Intelligence, 2002, 24(4):509-522.
         [2]Greg M, Serge B, Jitendra M. Efficient shape matching using shape contexts. IEEE Transactions Transactions on Pattern Analysis & Machine Intelligence, 2005, 27(11):1832-7.
学习shape context相关知识。
    图像的旋转、平移、轮廓和闭合曲线等因素有时候会限制形状匹配技术的发展，在这种情况下 Serge Belongie 等人提出了一种基于轮廓点集的,新的全局性的形状描述子:形状上下文（Shape Context）。物体的轮廓是具有感知意义的连续曲线，形状上下文分析是将选取的形状的轮廓能够用很多点的集合来表示,这些点可能是形状内部轮廓点或者是外部轮廓上的点，这些点没必要是一些特殊点例如曲率最大值或者拐点那样，在图像边缘检测的基础上，从边界得到点的集合，这些点可以用来表示形状。在离散的空间对向量进行分析凭借分布的位置描述形状,可以借用对数极坐标空间（Log-polar）来完成对向量的分布。对上述区域以圆心为中心进行编号，统计除了点的以外的轮廓点在各个区域的数量，把各个数字记录下来形成直方图，上述的直方图就可看作点的形状上下文。可以用相应数量的矩阵来存储轮廓点集的信息，那么这些矩阵就可以表达图像的轮廓信息。如下图所示：
    ![img](http://wx3.sinaimg.cn/mw1024/bfa72ceely1feps8klz07j20ia06c3zz.jpg)
