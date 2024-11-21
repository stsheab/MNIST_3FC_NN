//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream.h>
#include <math.h>
#include <Math.hpp>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

// open picture file --------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

        Graphics::TBitmap * buf = new Graphics::TBitmap;
        int *ptr;

        if(OpenPictureDialog1->Execute())
        {
                buf->LoadFromFile(OpenPictureDialog1->FileName);
        }

        Image2->Picture->Assign(buf);
                   
        // pxls colour format
        buf->PixelFormat = pf32bit;

        int w = buf->Width;
        int h = buf->Height;

        int RGB, R, G, B;
                           
        for(int j=0; j<h; j++)
        {
                ptr = (int *)buf->ScanLine[j];

                for(int i=0; i<w; i++)
                {    
                        RGB = ptr[i];
                        R = (RGB&0xFF);
                        G = ((RGB/256)&0xFF);
                        B = ((RGB/65536)&0xFF);
                
                        input[j*WIDTH + i] = 0.3*R + 0.11*B + 0.59*G;

                        // scaling to 0...1
                        input[j*WIDTH + i] /= 255.0;

                }
        }

        delete buf;
        buf=NULL;

}

// random file open ------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

        Graphics::TBitmap * buf = new Graphics::TBitmap;
        int *ptr;

        AnsiString file = "bmp\\img_" + FormatFloat("##0", (rand()%100)) + ".bmp";
        

        buf->LoadFromFile(file);
        Image2->Picture->Assign(buf);

        // pxls colour format
        buf->PixelFormat = pf32bit;

        int w = buf->Width;
        int h = buf->Height;

        int RGB, R, G, B;

        for(int j=0; j<h; j++)
        {
                ptr = (int *)buf->ScanLine[j];

                for(int i=0; i<w; i++)
                {    
                        RGB = ptr[i];
                        R = (RGB&0xFF);
                        G = ((RGB/256)&0xFF);
                        B = ((RGB/65536)&0xFF);

                        input[j*WIDTH + i] = 0.3*R + 0.11*B + 0.59*G;

                        // scaling to 0...1
                        input[j*WIDTH + i] /= 255.0;

                }
        }

        delete buf;
        buf=NULL;

}

// params loading ------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{

        // cntr
        __int64 start, stop, f;
        QueryPerformanceCounter((_LARGE_INTEGER*)&start);
        QueryPerformanceFrequency((_LARGE_INTEGER*)&f);

        
        load_bias0();
        load_bias1();
        load_bias2();

        load_weight0();
        load_weight1();
        load_weight2();


        QueryPerformanceCounter((_LARGE_INTEGER*)&stop);
        // in ms
        double time = 1000*(((double)(stop-start))/(double)f);
        Panel1->Caption = FormatFloat("###0.000",time) + " ms";
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
        for(int i=0; i<FIRST_LAYER; i++)
        {

                StringGrid1->Cells[0][i] = i;
                StringGrid1->Cells[1][i] = first_bias[i];

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
        for(int i=0; i<SECOND_LAYER; i++)
        {

                StringGrid1->Cells[0][i] = i;
                StringGrid1->Cells[1][i] = second_bias[i];

        }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
        for(int i=0; i<DIGITS; i++)
        {

                StringGrid1->Cells[0][i] = i;
                StringGrid1->Cells[1][i] = out_bias[i];

        }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
        for(int i=0; i<(StringGrid1->RowCount); i++)
        {
                StringGrid1->Cells[0][i] = "";
                StringGrid1->Cells[1][i] = "";
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        for(int i=0; i<cols0; i++)
        {
                StringGrid1->Cells[0][i] = i;
                StringGrid1->Cells[1][i] = first_weight[0][i];
        }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
        for(int i=0; i<cols0; i++)
        {
                StringGrid1->Cells[0][i] = i;
                StringGrid1->Cells[1][i] = first_weight[rows0-1][i];
        }
}

//---------------------------------------------------------------------------
    
void __fastcall TForm1::Button5Click(TObject *Sender)
{
        for(int row=0; row<rows1; row++)
        {
            for(int col=0; col<cols1; col++)
            {

                StringGrid1->Cells[0][row*cols1+col] = row*cols1+col;
                StringGrid1->Cells[1][row*cols1+col] = second_weight[row][col];

            }
        }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        for(int row=0; row<rows2; row++)
        {
            for(int col=0; col<cols2; col++)
            {

                StringGrid1->Cells[0][row*cols2+col] = row*cols2+col;
                StringGrid1->Cells[1][row*cols2+col] = out_weight[row][col];

            }
        }
}

// res -------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{

        maxx = -100000.0;
        predict = 0;

        for(int i=0; i<FIRST_LAYER; i++)
        {
                first_z[i] = 0.0;

                for(int k=0; k<WIDTH*HEIGHT; k++)
                {
                        first_z[i] += first_weight[i][k] * input[k];
                }

                first_activation[i] = 1.0/(1.0 + exp(-(first_z[i]+first_bias[i])));
        }

       
        for(int i=0; i<SECOND_LAYER; i++)
        {
                second_z[i] = 0.0;

                for(int k=0; k<FIRST_LAYER; k++)
                {
                        second_z[i] += second_weight[i][k] * first_activation[k];
                }

                second_activation[i] = 1.0/(1.0 + exp(-(second_z[i]+second_bias[i])));
                                                  
        }


        for(int i=0; i<DIGITS; i++)
        {
                out_z[i] = 0.0;

                for(int k=0; k<SECOND_LAYER; k++)
                {
                        out_z[i] += out_weight[i][k] * second_activation[k];
                }

                output[i] = out_z[i] + out_bias[i];

                if (output[i] >= maxx)
                {
                        maxx = output[i];
                        predict = i;
                }
                
        }

             
        Panel3->Caption = predict;

        for(int i=0; i<DIGITS; i++)
        {
                StringGrid1->Cells[0][i] = i;
                StringGrid1->Cells[1][i] = output[i];

        }
                
}
//---------------------------------------------------------------------------






