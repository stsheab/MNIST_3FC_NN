//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TImage *Image1;
        TOpenPictureDialog *OpenPictureDialog1;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TImage *Image2;
        TButton *Button7;
        TGroupBox *GroupBox5;
        TSavePictureDialog *SavePictureDialog1;
        TStringGrid *StringGrid3;
        TPanel *Panel1;
        TButton *Button2;
        TPanel *Panel2;
        TButton *Button3;
        TStringGrid *StringGrid1;
        TButton *Button4;
        TButton *Button5;
        TButton *Button10;
        TButton *Button11;
        TButton *Button13;
        TButton *Button14;
        TButton *Button15;
        TPanel *Panel3;
        TButton *Button6;
        TButton *Button8;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;


// net ----------------------------------------------------------------------

#define WIDTH 28
#define HEIGHT 28
#define DIGITS 10
#define FIRST_LAYER 500
#define SECOND_LAYER 100
             
typedef unsigned char uchar;

double input[WIDTH*HEIGHT];
double output[DIGITS];

double first_weight[FIRST_LAYER][WIDTH*HEIGHT];
double second_weight[SECOND_LAYER][FIRST_LAYER];
double out_weight[DIGITS][SECOND_LAYER];

double first_bias[FIRST_LAYER];
double second_bias[SECOND_LAYER];
double out_bias[DIGITS];

double first_z[FIRST_LAYER] = {0.0};
double second_z[SECOND_LAYER] = {0.0};
double out_z[DIGITS] = {0.0};

double first_activation[FIRST_LAYER];
double second_activation[SECOND_LAYER];

int rows0 = FIRST_LAYER;
int rows1 = SECOND_LAYER;
int rows2 = DIGITS;

int cols0 = WIDTH*HEIGHT;
int cols1 = FIRST_LAYER;
int cols2 = SECOND_LAYER;

int predict;
double maxx;

// params loading -----------------------------------------------------------

char* bias0 = "params/bias/b_0";
char* bias1 = "params/bias/b_1";
char* bias2 = "params/bias/b_2";
char* weight0 = "params/weight/w_0";
char* weight1 = "params/weight/w_1";
char* weight2 = "params/weight/w_2";


void load_weight0(void)
{
        ifstream in_weight0(weight0);

        for(int i=0; i<rows0*cols0; i++)
        {
                int row = (int)(i/cols0);
                int col = i%cols0;

                in_weight0 >> first_weight[row][col];
        }

        in_weight0.close();
}


void load_weight1(void)
{
        ifstream in_weight1(weight1);

        for(int i=0; i<rows1*cols1; i++)
        {
                int row = (int)(i/cols1);
                int col = i%cols1;

                in_weight1 >> second_weight[row][col];
        }

        in_weight1.close();
}


void load_weight2(void)
{
        ifstream in_weight2(weight2);

        for(int i=0; i<rows2*cols2; i++)
        {
                int row = (int)(i/cols2);
                int col = i%cols2;

                in_weight2 >> out_weight[row][col];
        }

        in_weight2.close();
}


void load_bias0(void)
{
        ifstream in_bias0(bias0);

        for(int i=0; i<FIRST_LAYER; i++)
        {
                in_bias0 >> first_bias[i];
        }

        in_bias0.close();
}


void load_bias1(void)
{
        ifstream in_bias1(bias1);

        for(int i=0; i<SECOND_LAYER; i++)
        {
                in_bias1 >> second_bias[i];
        }

        in_bias1.close();
}


void load_bias2(void)
{
        ifstream in_bias2(bias2);

        for(int i=0; i<DIGITS; i++)
        {
                in_bias2 >> out_bias[i];
        }

        in_bias2.close();
}


//---------------------------------------------------------------------------
#endif
 