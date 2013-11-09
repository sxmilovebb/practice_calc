// calcDlg.h : 头文件
//

#pragma once


// CcalcDlg 对话框
class CcalcDlg : public CDialog
{
// 构造
public:
	CcalcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtons(UINT btnid);
//	afx_msg void OnBnClicked_Exit();
//	afx_msg void OnUniChar(UINT Char, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnTCard(UINT /*idAction*/, DWORD /*dwActionData*/);
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
