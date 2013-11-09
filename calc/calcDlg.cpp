// calcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calc.h"
#include "calcDlg.h"

#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CcalcDlg �Ի���




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


// CcalcDlg ��Ϣ�������

BOOL CcalcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CcalcDlg::OnBnClickedButtons(UINT btnid)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		/////����ֱ�ӵ���OnKeyDown 
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
MessageBox("OnkeyDown");

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
