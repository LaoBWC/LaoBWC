#include "CharRecoHelper.h"
#include "SCMatch.h"

int main()
{
	PMatchShapeContextResult result = NULL;
	CharRecoHelper* m_pCharRecoHelper = new CharRecoHelper();
	SCMatch* m_pCharMatch = new SCMatch(m_pCharRecoHelper->GetTemplatePath(),m_pCharRecoHelper,m_pCharRecoHelper->GetExtractPoints());
	m_pCharMatch->LoadSCLibrary();


	IplImage* m_imgBk = cvLoadImage("./samples/s2/6.png",0);
	if (m_imgBk != NULL)
	{
		result = m_pCharMatch->Match(m_imgBk);		
	}
	std::cout << "最相似的匹配为：" << result->firstMatchResult << std::endl;
	std::cout << "第二相似的匹配为：" << result->secondMatchResult << std::endl;
	std::cout << "第三相似的匹配为：" << result->thirdMatchResult << std::endl;
	system("pause");
}
