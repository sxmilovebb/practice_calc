// calcDlg.h : ͷ�ļ�
//

#pragma once


// CcalcDlg �Ի���
class CcalcDlg : public CDialog
{
// ����
public:
	CcalcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
