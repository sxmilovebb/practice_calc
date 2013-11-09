// calcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calc.h"
#include "calcDlg.h"

#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CcalcDlg 对话框




CcalcDlg::CcalcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CcalcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalcDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDC_BUTTON_backspace, IDC_BUTTON_Rp, &CcalcDlg::OnBnClickedButtons)
	//ON_BN_CLICKED(IDC_BUTTON10, &CcalcDlg::OnBnClickedButtons)
//	ON_BN_CLICKED(IDC_BUTTON20, &CcalcDlg::OnBnClicked_Exit)
//	ON_WM_UNICHAR()
//	ON_WM_TCARD()
//ON_BN_CLICKED(IDC_BUTTON_1, &CcalcDlg::OnBnClickedButton1)
ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CcalcDlg 消息处理程序

BOOL CcalcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CcalcDlg::OnBnClickedButtons(UINT btnid)
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT1)->SetFocus();
	
}


//unsigned char codevk[]=
//{
//	VK_NUMPAD0,VK_NUMPAD1,VK_NUMPAD2,VK_NUMPAD3,VK_NUMPAD4,VK_NUMPAD5,VK_NUMPAD6,VK_NUMPAD7,VK_NUMPAD8,
//	VK_NUMPAD9,VK_BACK, 'C', VK_ADD, VK_SUBTRACT, VK_MULTIPLY, VK_DIVIDE, VK_DECIMAL,         
//};
//unsigned char codebtn[]={};

BOOL CcalcDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg-> message   ==   WM_KEYDOWN) 
	{ 
		/////或者直接调用OnKeyDown 
		//CString   strwParam; 
		//strwParam.Format( "%d   ",pMsg-> wParam); 
		//CDC*   pDC   =   GetDC(); 
		//pDC-> TextOut(10,10,strwParam); 
		//ReleaseDC(pDC); 
		switch(pMsg->wParam)
		{
		case VK_UP:
			MessageBox("VK_UP");
			break;

		//case  VK_MULTIPLY:
		//case VK_ADD:
		//case '0':
		//case '+':
		//	MessageBox("**");
		//	break;

		default:
			if( (GetKeyState(VK_SHIFT)&0XF0000000)&&
				((pMsg->wParam=='8')||(pMsg->wParam=='*')))
				MessageBox("Shift+8=*");
			break;

		}
	} 
	return   CDialog::PreTranslateMessage(pMsg); 
}
void CcalcDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
MessageBox("OnkeyDown");

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
