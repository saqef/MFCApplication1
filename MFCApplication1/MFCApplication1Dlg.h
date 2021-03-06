
// MFCApplication1Dlg.h: файл заголовка
//

#include <vector>
#include "tmmintrin.h" 

#pragma once


// Диалоговое окно CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialog
{
// Создание
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// стандартный конструктор
	CStatic*  pictureControl=nullptr;
	CSliderCtrl* sliderBright = nullptr;
	CSliderCtrl* sliderContr = nullptr;
	CImage image;
	COLORREF **matrix = nullptr;
	std::vector<COLORREF>vec;
	std::vector<__m128i>vec128;
	__m128i one;
	bool ready = false;
	int prevPositionBrigh = 50,
		prevPositionContr = 50,
		width = 0,
		height = 0,
		num = 0;

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	void changeBrigth();
	void changeContrast();
	int normalizeI(int value);
	int normalizeJ(int value);
	__m128i get_m128i(int i0);
	void setpix_m128i(__m128i vec, int i0);

};
