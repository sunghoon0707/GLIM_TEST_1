
// GLIM_TESTDlg.h: 헤더 파일
//

#pragma once
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#include "CDlgImage.h"
#include <iostream>

enum m_BorderColor
{
	RED_COLOR,
	BLUE_COLOR,
	YELLOW_COLOR,
	BLACK_COLOR,
};


// CGLIMTESTDlg 대화 상자
class CGLIMTESTDlg : public CDialogEx
{
// 생성입니다.
public:
	CGLIMTESTDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	// 생성시킬 다이알로그
	CDlgImage* m_pDlgImage;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GLIM_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CButton m_ColorChange;
	CEdit m_input_rds;
	CEdit m_CenterPoint;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnBlack();
	afx_msg void OnBnClickedBtnRed();
	afx_msg void OnBnClickedBtnBlue();
	afx_msg void OnBnClickedBtnYellow();
	afx_msg void OnBnClickedBtnClose();


private:
	void CircleDraw(m_BorderColor = BLACK_COLOR);
	void BorderDraw(CClientDC& dc, int n_centerX, int n_centerY, int n_r, COLORREF m_BorderColor, COLORREF IncircleColor);
	void CenterPoint(int n_centerX, int n_centerY);

};
