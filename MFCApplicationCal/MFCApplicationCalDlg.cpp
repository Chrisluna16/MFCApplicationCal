
// MFCApplicationCalDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "MFCApplicationCal.h"
#include "MFCApplicationCalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
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


// Cuadro de diálogo de CMFCApplicationCalDlg



CMFCApplicationCalDlg::CMFCApplicationCalDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATIONCAL_DIALOG, pParent)
	, m_resultado(_T(""))
	, m_resultado_entero(0)
	, m_binario(FALSE)
	, m_hexadecimal(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_resultado_entero = 0;
}

void CMFCApplicationCalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULTADO_EDIT, m_resultado);
	//  DDX_Text(pDX, IDC_RESULTADO_STATIC, m_resultado_entero);
	DDX_Check(pDX, IDC_bin, m_binario);
	DDX_Check(pDX, IDC_hex, m_hexadecimal);
}

BEGIN_MESSAGE_MAP(CMFCApplicationCalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0_BUTTON, &CMFCApplicationCalDlg::OnBnClicked0Button)
	ON_BN_CLICKED(IDC_1_BUTTON, &CMFCApplicationCalDlg::OnBnClicked1Button)
	ON_BN_CLICKED(IDC_2_BUTTON, &CMFCApplicationCalDlg::OnBnClicked2Button)
	ON_BN_CLICKED(IDC_3_BUTTON, &CMFCApplicationCalDlg::OnBnClicked3Button)
	ON_BN_CLICKED(IDC_4_BUTTON, &CMFCApplicationCalDlg::OnBnClicked4Button)
	ON_BN_CLICKED(IDC_5_BUTTON, &CMFCApplicationCalDlg::OnBnClicked5Button)
	ON_BN_CLICKED(IDC_6_BUTTON, &CMFCApplicationCalDlg::OnBnClicked6Button)
	ON_BN_CLICKED(IDC_7_BUTTON, &CMFCApplicationCalDlg::OnBnClicked7Button)
	ON_BN_CLICKED(IDC_8_BUTTON, &CMFCApplicationCalDlg::OnBnClicked8Button)
	ON_BN_CLICKED(IDC_9_BUTTON, &CMFCApplicationCalDlg::OnBnClicked9Button)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplicationCalDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_PUNTO_BUTTON, &CMFCApplicationCalDlg::OnBnClickedPuntoButton)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplicationCalDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplicationCalDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_DIV_BUTTON, &CMFCApplicationCalDlg::OnBnClickedDivButton)
	ON_BN_CLICKED(IDC_BUTTON_BORRAR, &CMFCApplicationCalDlg::OnBnClickedButtonBorrar)
	ON_BN_CLICKED(IDC_hex, &CMFCApplicationCalDlg::OnClickedHex)
	ON_BN_CLICKED(IDC_bin, &CMFCApplicationCalDlg::OnClickedBin)
END_MESSAGE_MAP()


// Controladores de mensajes de CMFCApplicationCalDlg

BOOL CMFCApplicationCalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
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

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CMFCApplicationCalDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CMFCApplicationCalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CMFCApplicationCalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int conteo=0;
int op1;
int op2;
int codigo_de_operacion;
int op1Add;
int op2Add;
int resultadoAdd;
int op1Res;
int op2Res;
int resultadoRes;
int op1Mul;
int op2Mul;
int resultadoMul;
int op1Div;
int op2Div;
int resultadoDiv;

void CMFCApplicationCalDlg::OnBnClicked0Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
	m_resultado = "0";
	m_resultado_entero = 0; 
	op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2;
		m_resultado_entero = op1 + 0;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClicked1Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "1";
		m_resultado_entero = 1;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 1;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClicked2Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	if (conteo == 0) {
		m_resultado = "2";
		m_resultado_entero = 2;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 2;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClicked3Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	if (conteo == 0) {
		m_resultado = "3";
		m_resultado_entero = 3;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 3;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClicked4Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	if (conteo == 0) {
		m_resultado = "4";
		m_resultado_entero = 4;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 4;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClicked5Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	if (conteo == 0) {
		m_resultado = "5";
		m_resultado_entero = 5;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 5;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClicked6Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	if (conteo == 0) {
		m_resultado = "6";
		m_resultado_entero = 6;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 6;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClicked7Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	if (conteo == 0) {
		m_resultado = "7";
		m_resultado_entero = 7;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 7;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClicked8Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	if (conteo == 0) {
		m_resultado = "8";
		m_resultado_entero = 8;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 8;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClicked9Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	if (conteo == 0) {
		m_resultado = "9";
		m_resultado_entero = 9;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 9;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClickedButton2()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	codigo_de_operacion = 1; 
	op1Add = op1;
	op2Add = op2;
	resultadoAdd = m_resultado_entero;
	conteo = 0;
	CString MyCadena;
	MyCadena.Format(L"%d +", resultadoAdd);
	m_resultado = MyCadena;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClickedPuntoButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	switch (codigo_de_operacion)
	{
	case 1:
		m_resultado_entero = resultadoAdd + op1;
		break;
	case 2:
		m_resultado_entero = resultadoRes - op1;
		break;
	case 3:
		m_resultado_entero = resultadoMul * op1;
		break;
	case 4:
		m_resultado_entero = resultadoDiv / op1;
		break;
	default:
		break;
	}
	CString MyCadena;
	MyCadena.Format(L"= %d", m_resultado_entero);
	m_resultado = MyCadena;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClickedButton3()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	codigo_de_operacion = 2;
	op1Res = op1;
	op2Res = op2;
	resultadoRes = m_resultado_entero;
	conteo = 0;
	CString MyCadena;
	MyCadena.Format(L"%d -", resultadoRes);
	m_resultado = MyCadena;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClickedButton4()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	codigo_de_operacion = 3;
	op1Mul = op1;
	op2Mul = op2;
	resultadoMul = m_resultado_entero;
	conteo = 0;
	CString MyCadena;
	MyCadena.Format(L"%d *", resultadoMul);
	m_resultado = MyCadena;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClickedDivButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	codigo_de_operacion = 4;
	op1Div = op1;
	op2Div = op2;
	resultadoDiv = m_resultado_entero;
	conteo = 0;
	CString MyCadena;
	MyCadena.Format(L"%d /", resultadoDiv);
	m_resultado = MyCadena;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnBnClickedButtonBorrar()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_entero = 0;
	resultadoAdd = 0;
	resultadoRes = 0;
	resultadoMul = 0;
	resultadoDiv = 0;
	CString MyCadena;
	MyCadena.Format(L"%d", resultadoAdd, resultadoRes, resultadoDiv, resultadoMul);
	m_resultado = MyCadena;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnClickedHex()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (m_hexadecimal == TRUE) {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
		m_binario = FALSE;
	}
	CString MyCadena;
	MyCadena.Format(L"%X", m_resultado_entero);
	m_resultado = MyCadena;
	UpdateData(FALSE);
}


void CMFCApplicationCalDlg::OnClickedBin()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (m_binario == TRUE) {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(FALSE);
		m_hexadecimal = FALSE;

		int a[10], n, i;
		UpdateData(TRUE); 
		n = m_resultado_entero;
		for (i = 0; n > 0; i++) {
			a[i] = n % 2;
			n = n / 2;
		}
		m_resultado = "";
		UpdateData(FALSE);
		for (i = i - 1; i >= 0; i--) {
			m_resultado_entero = a[i];
			CString MyCadena;
			MyCadena.Format(L"%d", m_resultado_entero);
			m_resultado += MyCadena;
		}
	}
	else {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
		m_hexadecimal = FALSE;
	}

	UpdateData(FALSE);

}
