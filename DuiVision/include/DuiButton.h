#pragma once
#include "ControlBase.h"

class CDuiButton : public CControlBaseFont
{
	DUIOBJ_DECLARE_CLASS_NAME(CDuiButton, "button")
public:
	CDuiButton(HWND hWnd, CDuiObject* pDuiObject);
	CDuiButton(HWND hWnd, CDuiObject* pDuiObject, UINT uControlID, CRect rc, CString strTitle = TEXT(""), BOOL bIsVisible = TRUE, BOOL bIsDisable = FALSE, BOOL bIsPressDown = FALSE);
	virtual ~CDuiButton(void);

	void SetMaxIndex(int nMaxIndex) { m_nMaxIndex = nMaxIndex; }

	virtual BOOL SetControlFocus(BOOL bFocus);

protected:

	virtual BOOL OnControlMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnControlLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnControlLButtonUp(UINT nFlags, CPoint point);
	virtual BOOL OnControlKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	virtual	void SetControlDisable(BOOL bIsDisable);
	virtual	BOOL OnControlTimer();
	virtual void DrawControl(CDC &dc, CRect rcUpdate);

public:
	enumButtonState		m_enButtonState;	// ��ť״̬
	Color				m_clrText;			// ������ɫ
	int					m_nIndex;			// ����Ч���Ĺ�������
	int					m_nMaxIndex;		// ����Ч�����������
	BOOL				m_bTimer;			// �Ƿ����ý���Ч����ʱ��
	BOOL				m_bIsFocus;			// ��ǰ�Ƿ��ڽ���״̬

	DUI_IMAGE_ATTRIBUTE_DEFINE(Btn);		// ���尴ťͼƬ
	DUI_DECLARE_ATTRIBUTES_BEGIN()
		DUI_COLOR_ATTRIBUTE("crtext", m_clrText, FALSE)
		DUI_INT_ATTRIBUTE("animate", m_bTimer, TRUE)
		DUI_INT_ATTRIBUTE("maxindex", m_nMaxIndex, TRUE)
		DUI_CUSTOM_ATTRIBUTE("img-btn", OnAttributeImageBtn)
    DUI_DECLARE_ATTRIBUTES_END()
};

// ͼƬ��ť,���ܺͻ����İ�ť��ȫ��ͬ,ֻ��Ϊ�˼���֮ǰ�Ŀؼ�����
class CImageButton : public CDuiButton
{
	DUIOBJ_DECLARE_CLASS_NAME(CImageButton, "imgbtn")
public:
	CImageButton(HWND hWnd, CDuiObject* pDuiObject);
	CImageButton(HWND hWnd, CDuiObject* pDuiObject, UINT uControlID, CRect rc, BOOL bAnimation = true, CString strTitle = TEXT(""), BOOL bIsVisible = TRUE, BOOL bIsDisable = FALSE, BOOL bIsPressDown = FALSE);
	~CImageButton(void) {};
};