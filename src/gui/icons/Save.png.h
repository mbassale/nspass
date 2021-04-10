#ifndef SAVE_PNG_H
#define SAVE_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char Save_png[] =
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x10, 
	0x00, 0x00, 0x00, 0x10, 0x08, 0x06, 0x00, 0x00, 0x00, 0x1F, 
	0xF3, 0xFF, 0x61, 0x00, 0x00, 0x00, 0x06, 0x62, 0x4B, 0x47, 
	0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF9, 0x43, 0xBB, 
	0x7F, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 
	0x00, 0x0B, 0x13, 0x00, 0x00, 0x0B, 0x13, 0x01, 0x00, 0x9A, 
	0x9C, 0x18, 0x00, 0x00, 0x00, 0x07, 0x74, 0x49, 0x4D, 0x45, 
	0x07, 0xD5, 0x0B, 0x0A, 0x0D, 0x37, 0x0F, 0x9E, 0x2A, 0xD8, 
	0xBF, 0x00, 0x00, 0x00, 0x8C, 0x74, 0x45, 0x58, 0x74, 0x43, 
	0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x00, 0x4D, 0x65, 0x6E, 
	0x75, 0x2D, 0x73, 0x69, 0x7A, 0x65, 0x64, 0x20, 0x69, 0x63, 
	0x6F, 0x6E, 0x0A, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 0x3D, 
	0x3D, 0x3D, 0x3D, 0x0A, 0x0A, 0x28, 0x63, 0x29, 0x20, 0x32, 
	0x30, 0x30, 0x33, 0x20, 0x4A, 0x61, 0x6B, 0x75, 0x62, 0x20, 
	0x27, 0x6A, 0x69, 0x6D, 0x6D, 0x61, 0x63, 0x27, 0x20, 0x53, 
	0x74, 0x65, 0x69, 0x6E, 0x65, 0x72, 0x2C, 0x20, 0x0A, 0x68, 
	0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x6A, 0x69, 0x6D, 0x6D, 
	0x61, 0x63, 0x2E, 0x6D, 0x75, 0x73, 0x69, 0x63, 0x68, 0x61, 
	0x6C, 0x6C, 0x2E, 0x63, 0x7A, 0x0A, 0x0A, 0x63, 0x72, 0x65, 
	0x61, 0x74, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 
	0x74, 0x68, 0x65, 0x20, 0x47, 0x49, 0x4D, 0x50, 0x2C, 0x0A, 
	0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x77, 0x77, 0x77, 
	0x2E, 0x67, 0x69, 0x6D, 0x70, 0x2E, 0x6F, 0x72, 0x67, 0x67, 
	0x8A, 0xC7, 0x47, 0x00, 0x00, 0x02, 0x84, 0x49, 0x44, 0x41, 
	0x54, 0x38, 0xCB, 0x9D, 0x92, 0x4D, 0x48, 0x54, 0x61, 0x14, 
	0x86, 0x9F, 0xB9, 0xDD, 0xF1, 0xE6, 0xCF, 0xE4, 0x4C, 0xE0, 
	0xB5, 0x31, 0xCD, 0x91, 0xB2, 0x51, 0x6C, 0x51, 0x51, 0x34, 
	0x26, 0x14, 0xB8, 0xC8, 0x16, 0x45, 0x14, 0x2E, 0x42, 0x28, 
	0x2C, 0x82, 0x8A, 0xA9, 0xC1, 0x56, 0x2D, 0x2A, 0xCA, 0x45, 
	0x11, 0x54, 0x10, 0x06, 0x52, 0xB4, 0x28, 0x0A, 0x22, 0xB0, 
	0x28, 0x28, 0x6A, 0x5B, 0xD0, 0x22, 0x89, 0x44, 0x8A, 0xA6, 
	0x45, 0x99, 0x54, 0x6A, 0x86, 0xA4, 0xE8, 0xDC, 0x9B, 0xCE, 
	0xFD, 0xF9, 0x4E, 0x0B, 0x61, 0x6C, 0xB2, 0x36, 0xBD, 0x9B, 
	0xF3, 0xC1, 0xE1, 0x3C, 0x9C, 0xF7, 0x3D, 0x5F, 0xE0, 0xC8, 
	0xD9, 0xE3, 0x27, 0x3F, 0x5B, 0x15, 0xDA, 0xD8, 0xB8, 0x33, 
	0x09, 0x54, 0x01, 0x5B, 0x81, 0x86, 0xA0, 0x26, 0xD9, 0xD0, 
	0xC2, 0x9F, 0x3F, 0x16, 0x19, 0xCE, 0xCD, 0xBB, 0xE7, 0xCF, 
	0x9D, 0xE0, 0x1F, 0x0A, 0x34, 0x77, 0x74, 0xED, 0x8D, 0xAD, 
	0xAC, 0x8F, 0x55, 0x97, 0x9B, 0x83, 0xAB, 0x6B, 0xCA, 0x3A, 
	0xAA, 0x23, 0x85, 0x6B, 0x6D, 0xCF, 0x27, 0xFD, 0x2D, 0xC3, 
	0xEB, 0xDE, 0xE7, 0xEA, 0xC3, 0xD7, 0x51, 0xE2, 0x91, 0x37, 
	0xCB, 0xBA, 0x3B, 0xEF, 0x0C, 0xFF, 0x15, 0x90, 0x3C, 0x7D, 
	0xBE, 0xDB, 0x9D, 0x1A, 0x3B, 0xEC, 0x89, 0xC6, 0xA8, 0x1F, 
	0x66, 0xDA, 0x28, 0x63, 0x81, 0x1E, 0xA4, 0xAD, 0x65, 0x23, 
	0xCB, 0x2B, 0x16, 0x73, 0xF9, 0xFE, 0x0B, 0xFC, 0xA1, 0x3E, 
	0x62, 0x05, 0xE3, 0x7F, 0x9B, 0xEF, 0x24, 0x79, 0x2C, 0x25, 
	0x5F, 0x46, 0x06, 0x44, 0x44, 0x64, 0xE0, 0x73, 0x5A, 0x7A, 
	0xD3, 0x03, 0x92, 0xBA, 0xF6, 0x44, 0x12, 0x07, 0x2F, 0x48, 
	0xCF, 0xAB, 0x2F, 0xD2, 0xF5, 0xF4, 0xAD, 0xB4, 0x9E, 0xBA, 
	0x2E, 0xEF, 0x06, 0x87, 0xE5, 0x77, 0x59, 0x96, 0x25, 0xA9, 
	0x8E, 0xA4, 0xE8, 0x86, 0xEE, 0xB3, 0xB4, 0x3C, 0xC6, 0xC4, 
	0xC4, 0x04, 0xE1, 0x92, 0x72, 0xB4, 0xC0, 0x24, 0x85, 0xE2, 
	0x00, 0xD0, 0xF7, 0x71, 0x14, 0xB3, 0x44, 0xE7, 0xFB, 0x78, 
	0x86, 0xF7, 0x03, 0x9F, 0x58, 0xB2, 0xA8, 0x10, 0x02, 0x00, 
	0x42, 0x41, 0x41, 0x01, 0x00, 0xBA, 0xE7, 0x82, 0x28, 0xC1, 
	0x57, 0x8A, 0xED, 0x27, 0x6E, 0xCC, 0xDB, 0xB1, 0x77, 0x70, 
	0x02, 0xD7, 0xF3, 0xB9, 0xD8, 0xF3, 0x92, 0x8B, 0x3D, 0x2F, 
	0x01, 0x78, 0x7C, 0x76, 0x1F, 0xC8, 0x6C, 0x5F, 0x03, 0x50, 
	0xA2, 0x50, 0xBE, 0xA2, 0xEB, 0x50, 0x23, 0x00, 0xED, 0xBB, 
	0x77, 0xD2, 0x98, 0x58, 0xC7, 0xCC, 0x8C, 0x4D, 0x34, 0xA4, 
	0xD1, 0x94, 0x58, 0xCF, 0xDE, 0xD6, 0xED, 0x00, 0xEC, 0x69, 
	0x5E, 0x81, 0xF2, 0x15, 0x22, 0x32, 0x07, 0x10, 0x11, 0x22, 
	0x91, 0x30, 0x15, 0x65, 0x31, 0x2E, 0x1D, 0x58, 0xC7, 0xCD, 
	0xBB, 0x0F, 0x88, 0xC7, 0xAA, 0xD0, 0x08, 0xA0, 0x11, 0x20, 
	0x51, 0x5F, 0xCD, 0xAD, 0x7B, 0x8F, 0x68, 0xDB, 0x5C, 0xC3, 
	0x8E, 0xA6, 0xF5, 0x14, 0x15, 0x17, 0xE5, 0x03, 0x00, 0x2C, 
	0xCB, 0xC2, 0x34, 0x4D, 0xAA, 0xA3, 0xB5, 0x39, 0x48, 0xE3, 
	0xAA, 0xE5, 0xD4, 0xC6, 0x2A, 0xB9, 0x7C, 0xFB, 0x21, 0x6D, 
	0x9B, 0x6B, 0xD8, 0xB5, 0x29, 0x81, 0x69, 0x9A, 0x38, 0x8E, 
	0x93, 0xB3, 0xA8, 0x03, 0x28, 0xA5, 0xB0, 0x6D, 0x1B, 0x00, 
	0xD3, 0x34, 0x31, 0x4D, 0x93, 0xEE, 0xA3, 0x85, 0x1C, 0xBB, 
	0xDA, 0x43, 0xD6, 0xF5, 0xD9, 0xDF, 0x52, 0x4F, 0xFB, 0xB6, 
	0x2D, 0x68, 0x9A, 0xC6, 0xD4, 0xD4, 0x14, 0xB6, 0x6D, 0x13, 
	0x0A, 0x85, 0xE6, 0x00, 0x86, 0x61, 0x50, 0x59, 0x59, 0x99, 
	0x17, 0xDE, 0x9A, 0x86, 0x0D, 0x3C, 0xBB, 0xB2, 0x01, 0x00, 
	0xDB, 0xB6, 0x71, 0x1C, 0x87, 0xE9, 0xE9, 0xE9, 0x79, 0x21, 
	0xEB, 0x00, 0xFD, 0xFD, 0xFD, 0xB8, 0xAE, 0x9B, 0xD7, 0xF0, 
	0x3C, 0x0F, 0x5D, 0xD7, 0x73, 0xEF, 0x3F, 0x15, 0x89, 0x44, 
	0xF2, 0x33, 0xF0, 0x3C, 0x8F, 0x74, 0x3A, 0xCD, 0xC8, 0xC8, 
	0x08, 0x99, 0x4C, 0x06, 0x11, 0x41, 0x44, 0x30, 0x0C, 0x83, 
	0xA1, 0xA1, 0x21, 0x42, 0xA1, 0x50, 0xAE, 0x5A, 0x96, 0x85, 
	0x65, 0x59, 0xF9, 0x57, 0x50, 0x4A, 0x51, 0x5C, 0x5C, 0x44, 
	0x30, 0x18, 0xCC, 0x7D, 0x12, 0x00, 0xD7, 0x75, 0x11, 0x35, 
	0x0B, 0x13, 0x35, 0x7B, 0x3E, 0xE5, 0xFB, 0xF9, 0x16, 0xC2, 
	0xE1, 0x30, 0xA5, 0xA5, 0xA5, 0x44, 0xA3, 0x51, 0x00, 0xB2, 
	0xD9, 0x2C, 0x40, 0x2E, 0xED, 0x78, 0x5D, 0x1C, 0xA5, 0x14, 
	0xF1, 0xBA, 0x3A, 0x94, 0x52, 0x2C, 0x89, 0x46, 0x73, 0x96, 
	0x03, 0xA9, 0x8E, 0xE4, 0x19, 0xE0, 0x34, 0xFF, 0xA7, 0xCE, 
	0x5F, 0x93, 0x3B, 0x33, 0x4C, 0xD5, 0x22, 0x62, 0x6D, 0x00, 
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 
	0x82, 
};

wxBitmap& Save_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( Save_png, sizeof( Save_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
}


#endif //SAVE_PNG_H
