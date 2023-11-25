
// GLIM_TESTDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "GLIM_TEST.h"
#include "GLIM_TESTDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGLIMTESTDlg 대화 상자



CGLIMTESTDlg::CGLIMTESTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GLIM_TEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	m_pDlgImage = nullptr;
}

void CGLIMTESTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_input_rds);
	DDX_Control(pDX, IDC_EDIT2, m_CenterPoint);
	DDX_Control(pDX, IDC_CHECK_COLOR, m_ColorChange);
}

BEGIN_MESSAGE_MAP(CGLIMTESTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_BLACK, &CGLIMTESTDlg::OnBnClickedBtnBlack)
	ON_BN_CLICKED(IDC_BTN_RED, &CGLIMTESTDlg::OnBnClickedBtnRed)
	ON_BN_CLICKED(IDC_BTN_BLUE, &CGLIMTESTDlg::OnBnClickedBtnBlue)
	ON_BN_CLICKED(IDC_BTN_YELLOW, &CGLIMTESTDlg::OnBnClickedBtnYellow)
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CGLIMTESTDlg::OnBnClickedBtnClose)
END_MESSAGE_MAP()


// CGLIMTESTDlg 메시지 처리기

BOOL CGLIMTESTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	//MoveWindow(0, 0, 900, 490);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_CDlgImage, this);
	m_pDlgImage->ShowWindow(SW_SHOW);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGLIMTESTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CGLIMTESTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGLIMTESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGLIMTESTDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	delete m_pDlgImage;
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void CGLIMTESTDlg::CircleDraw(m_BorderColor color)
{

	CClientDC dc(m_pDlgImage);

	CString str_rds;
	m_input_rds.GetWindowText(str_rds);
	int n_r = _wtoi(str_rds);

	if (str_rds.IsEmpty())
	{
		AfxMessageBox(_T("반지름을 입력해주세요"));
		return;
	}

	if (n_r >= 20 && n_r <= 220)
	{
		// 가로,세로 길이를 이미지 객체에서 가져옴
		int nWidth = m_pDlgImage->m_Image.GetWidth();
		int nHeight = m_pDlgImage->m_Image.GetHeight();

		//배경색 하얀색으로 초기화
		dc.FillSolidRect(0, 0, nWidth, nHeight, RGB(255, 255, 255));

		// 화면을 업데이트, 이렇게 하는 방식도 있음
		// Invalidate() 를 강제 호출하여 m_pDlgImage의 m_Image 를 다시 그림
		// Invalidate();
		// UpdateWindow();


		// 원 중심 최대 허용 좌표
		int n_maxX = nWidth - n_r;
		int n_maxY = nHeight - n_r;

		// 랜덤 좌표
		int n_centerX = n_r + rand() % (n_maxX - n_r);
		int n_centerY = n_r + rand() % (n_maxY - n_r);

		std::cout << n_centerX << "," << n_centerY << std::endl;

		COLORREF m_BorderColor;

		switch (color)
		{
		case RED_COLOR:
			m_BorderColor = RGB(255, 0, 0);
			break;
		case BLUE_COLOR:
			m_BorderColor = RGB(0, 0, 255);
			break;
		case YELLOW_COLOR:
			m_BorderColor = RGB(255, 255, 0);
			break;
		default:
			m_BorderColor = RGB(0, 0, 0); // 기본값 검은색
			break;
		}
		CenterPoint(n_centerX, n_centerY);

		// BOOL 형으로 체크여부 확인
		BOOL b_Check = m_ColorChange.GetCheck();

		// 디폴트값
		COLORREF IncircleColor = RGB(255, 255, 255);

		// 클릭되었을때!
		if (b_Check)
		{
			// 256가지 랜덤 색상 생성
			int red = rand() % 256;
			int green = rand() % 256;
			int blue = rand() % 256;

			// RGB 색상 설정
			IncircleColor = RGB(red, green, blue);
		}

		BorderDraw(dc, n_centerX, n_centerY, n_r, m_BorderColor, IncircleColor);

	}
	else
	{
		AfxMessageBox(_T("20 ~ 220 범위 안에서 적어주세요"));
	}

}

void CGLIMTESTDlg::BorderDraw(CClientDC& dc, int n_centerX, int n_centerY, int n_r, COLORREF m_BorderColor, COLORREF IncircleColor)
{


	// 원 그리기
	CBrush CircleBrush(IncircleColor);
	CBrush* oldBrush = dc.SelectObject(&CircleBrush);
	dc.Ellipse(n_centerX - n_r, n_centerY - n_r, n_centerX + n_r, n_centerY + n_r);


	// 테두리 두께
	int n_penWidth = 4;

	// 테두리 그리기
	CPen draw_Pen(PS_SOLID, n_penWidth, m_BorderColor);
	CPen* oldPen = dc.SelectObject(&draw_Pen);
	dc.Ellipse(n_centerX - n_r, n_centerY - n_r, n_centerX + n_r, n_centerY + n_r);
	dc.SelectObject(oldPen);

	// 복원
	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);

	// 가운데 십자가
	int n_point = n_r / 10;
	if (n_point <= n_r)
	{
		n_point = 5;
	}

	// Line 에는 시작점부터 끝점을 말하는건데 끝점이 포함되지 않기에 +1 을 해줘야함
	// (centerX - point , centerY) 시작점 설정
	// (centerX - point +1 , centerY) 선긋기
	dc.MoveTo(n_centerX - n_point, n_centerY);
	dc.LineTo(n_centerX + n_point + 1, n_centerY);
	dc.MoveTo(n_centerX, n_centerY - n_point);
	dc.LineTo(n_centerX, n_centerY + n_point + 1);

}


// 센터 무게중심 값 m_CenterPoint 에 띄우기
void CGLIMTESTDlg::CenterPoint(int centerX, int centerY)
{
	CString str_CenterPoint;
	str_CenterPoint.Format(_T("%d, %d"), centerX, centerY);

	m_CenterPoint.SetWindowTextW(str_CenterPoint);
}




void CGLIMTESTDlg::OnBnClickedBtnBlack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CircleDraw();
}


void CGLIMTESTDlg::OnBnClickedBtnRed()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CircleDraw(RED_COLOR);
}


void CGLIMTESTDlg::OnBnClickedBtnBlue()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CircleDraw(BLUE_COLOR);
}


void CGLIMTESTDlg::OnBnClickedBtnYellow()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CircleDraw(YELLOW_COLOR);
}


void CGLIMTESTDlg::OnBnClickedBtnClose()
{
	OnCancel();

	// 세개 모두 프로그램 종료시키는 함수
	// OnCancer()
	// OnOK()
	// PostQuitMessage(0)
}
