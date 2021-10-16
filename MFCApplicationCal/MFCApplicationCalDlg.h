
// MFCApplicationCalDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CMFCApplicationCalDlg
class CMFCApplicationCalDlg : public CDialogEx
{
// Construcción
public:
	CMFCApplicationCalDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATIONCAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClicked0Button();
	CString m_resultado;
//	int m_resultado_entero;
	afx_msg void OnBnClicked1Button();
	afx_msg void OnBnClicked2Button();
	afx_msg void OnBnClicked3Button();
	afx_msg void OnBnClicked4Button();
	afx_msg void OnBnClicked5Button();
	afx_msg void OnBnClicked6Button();
	afx_msg void OnBnClicked7Button();
	afx_msg void OnBnClicked8Button();
	afx_msg void OnBnClicked9Button();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedPuntoButton();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedDivButton();
	afx_msg void OnBnClickedButtonBorrar();
	int m_resultado_entero;
	afx_msg void OnClickedHex();
	afx_msg void OnClickedBin();
	BOOL m_binario;
	BOOL m_hexadecimal;
};
