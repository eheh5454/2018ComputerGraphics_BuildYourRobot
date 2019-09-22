#include "Map.h"

Map::Map()
{
	
}
Map::~Map()
{

}
void Map::Draw()
{
	glPushMatrix();
	{
		glPushMatrix();
		{
			glTranslatef(0, 0, 0);
			//glBindTexture(GL_TEXTURE_2D, texture_object);   //텍스처와 객체를 결합한다.
			//pBytes = LoadDIBitmap("floor2.bmp", &info);   //이미지 로딩을 한다
			//											 //텍스처 설정 정의를 한다. 
			//glTexImage2D(GL_TEXTURE_2D, 0, 3, 1024, 1024, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
			////텍스처 파라미터 설정
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			//// 텍스처 모드 설정 
			//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
			//// 텍스처 매핑 활성화
			//glEnable(GL_TEXTURE_2D);
			glColor4f(0.5f, 0.5f, 0.5f, 1.0f);

			glBegin(GL_QUADS);
			{
				glNormal3f(0, 1, 0);
				glTexCoord2f(0, 1);
				glVertex3f(-WindowWidth, 0, -WindowWidth);
				glTexCoord2f(0, 0);
				glVertex3f(WindowWidth, 0, -WindowWidth);
				glTexCoord2f(1, 0);
				glVertex3f(WindowWidth, 0, WindowWidth);
				glTexCoord2f(1, 1);
				glVertex3f(-WindowWidth, 0, WindowWidth);
			}
			glEnd();
		}
		glPopMatrix();

	}
	glPopMatrix();
}
void Map::Update()
{

}