#include "resource.h"

//////////////////////////////////////
//			resource.cpp			//
//									//
//	게임에서 활용되는 resource들을	//
//	모아놓은 cpp입니다.				//
//	1. 맵에서 사용되는 Obj			//
//	2. 투영(Projection)관련 함수		//
//	3. 비트맵(글씨), 텍스쳐(그림)		//
//									//
//////////////////////////////////////

void Draw_GhostObj() {
	glEnable(GL_BLEND);
	glPushMatrix();
	{
		glRotatef(0, 0, 1, 0);
		glBlendFunc(GL_ONE, GL_ONE);
		glColor3f(1.0f, 1.0f, 1.0f);

		glTranslatef(0.0f, 0.85f, 0.0f);
		glutSolidSphere(0.9f, 20, 20);

		glTranslatef(0.0f, 1.15f, 0.0f);
		glutSolidSphere(0.50f, 20, 20);

		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		glTranslatef(0.07f, 0.14f, 0.45f);
		glutSolidSphere(0.13f, 10, 10);
		glTranslatef(-0.2f, 0.0f, 0.0f);
		glutSolidSphere(0.13f, 10, 10);
		glPopMatrix();

		glColor3f(1.0f, 0.5f, 0.5f);
		glutSolidCone(0.2f, 1.0f, 10, 2);
	}
	glPopMatrix();
	glDisable(GL_BLEND);

	//glBegin(GL_LINE_LOOP);
	//{
	//	glVertex3f(static_ghost[i].max_x, 1, static_ghost[i].max_z);
	//	glVertex3f(static_ghost[i].min_x, 1, static_ghost[i].max_z);
	//	glVertex3f(static_ghost[i].min_x, 1, static_ghost[i].min_z);
	//	glVertex3f(static_ghost[i].max_x, 1, static_ghost[i].min_z);
	//}
	//glEnd();
	glLineWidth(1); // 블럭 위치-
}

void Draw_PlayerObj()
{
	glPushMatrix();
	{
		glTranslatef(0, 0.5, 0);
		glColor3f(1, 8, 1);
		glScalef(0.4, 0.75, 0.4);

		glBegin(GL_QUADS);
		{
			//윗면
			glColor3f(0.0f, 0.0f, 1.0f);// Blue
			glVertex3f(1, 1, 1);
			glColor3f(0.0f, 1.0f, 0.0f);// Green
			glVertex3f(1, 1, -1);
			glColor3f(1.0f, 0.0f, 0.0f);// Red
			glVertex3f(-1, 1, -1);
			glColor3f(1.0f, 1.0f, 0.0f);// Yellow
			glVertex3f(-1.0, 1.0, 1.0f);

			//뒷면
			glColor3f(0.0f, 1.0f, 0.0f);// Green
			glVertex3f(1, 1, -1);
			glColor3f(0.0f, 0.0f, 0.0f);// Black
			glVertex3f(1, -1, -1);
			glColor3f(1.0f, 1.0f, 1.0f);// White
			glVertex3f(-1, -1, -1);
			glColor3f(1.0f, 0.0f, 0.0f);// Red
			glVertex3f(-1, 1, -1);

			//아랫면
			glColor3f(1.0f, 0.0, 1.0f);// Magenta
			glVertex3f(-1, -1, 1);
			glColor3f(1.0f, 1.0f, 1.0f);// White
			glVertex3f(-1, -1, -1);
			glColor3f(0.0f, 0.0f, 0.0f);// Black
			glVertex3f(1, -1, -1);
			glColor3f(0.0f, 1.0f, 1.0f);// Cyan
			glVertex3f(1, -1, 1);

			//왼면
			glColor3f(1.0f, 0.0f, 0.0f);// Red
			glVertex3f(-1, 1, -1);
			glColor3f(1.0f, 1.0f, 1.0f);// White
			glVertex3f(-1, -1, -1);
			glColor3f(1.0f, 0.0, 1.0f);// Magenta
			glVertex3f(-1, -1, 1);
			glColor3f(1.0f, 1.0f, 0.0f);// Yellow
			glVertex3f(-1.0, 1.0, 1.0f);

			//오른면

			glColor3f(0.0f, 0.0f, 1.0f);// Blue
			glVertex3f(1, 1, 1);
			glColor3f(0.0f, 1.0f, 1.0f);// Cyan
			glVertex3f(1, -1, 1);
			glColor3f(0.0f, 0.0f, 0.0f);// Black
			glVertex3f(1, -1, -1);
			glColor3f(0.0f, 1.0f, 0.0f);// Green
			glVertex3f(1, 1, -1);
		}
		glEnd();

		glLineWidth(2);
		glColor3f(0.5, 0.5, 0.5);
		//glBegin(GL_LINE_LOOP);
		//{
		//	glVertex3f(static_person.max_x + 15, 2, static_person.max_z + 15);
		//	glVertex3f(static_person.min_x + 15, 2, static_person.max_z + 15);
		//	glVertex3f(static_person.min_x + 15, 2, static_person.min_z + 15);
		//	glVertex3f(static_person.max_x + 15, 2, static_person.min_z + 15);
		//}
		//glEnd();
		glLineWidth(1);

	}
	glPopMatrix();
}

void Draw_MazeObj()
{
	glPushMatrix();
	{
		glColor3f(0.65,0.65,0.65);
		glTranslatef(0, 1.1, 0);
		glutSolidCube(1);

		glColor3f(0.5, 0.5, 0.5);
		glTranslatef(0, 1.1, 0);
		glutSolidCube(1);

		glColor3f(0.3, 0.3, 0.3);
		glTranslatef(0, 1.1, 0);
		glutSolidCube(1);

		glColor3f(0.8, 0.8, 0.8);
		glTranslatef(0, 1.1, 0);
		glutSolidCube(1);
	}
	glPopMatrix();
}

void Draw_SideLineObj()
{
	glColor3f(0.0, 0.0, 0.0);

	glPushMatrix();
	{
		glNormal3f(0, 1, 0);
		glTranslatef(0, 1.1, 0);
		glutSolidCube(1);

		glTranslatef(0, 1.1, 0);
		glutSolidCube(1);

		glTranslatef(0, 1.1, 0);
		glutSolidCube(1);

		glTranslatef(0, 1.1, 0);
		glutSolidCube(1);

		glTranslatef(0, 1.1, 0);
		glutSolidCube(1);
	}
	glPopMatrix();
}

void Draw_TrackObj()
{
	glPushMatrix();
	{
		glEnable(GL_BLEND);
		glPushMatrix();
		{
			//glScaled(1.5,1,1.5);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE);
			//glColor3f(0.7, 0.2, 0.2);
			glTranslatef(0, 0.6, 0);
			glColor4f(0, 0.5, 0.5, 0.8);
			glRotatef(obj_rot, 0, 1, 0);
			glutSolidSphere(0.1, 15, 15);
			//glutSolidCube(0.1);
		}
		glPopMatrix();

		glPushMatrix();
		{
			//glScaled(1.5, 1, 1.5);
			glColor4f(0.0, 0.0, 0.8, 0.5);
			glTranslatef(0, 0.6, 0);
			glRotatef(obj_rot + 5, 0, 1, 0);
			glRotatef(90, -1, 0, -1);
			//glutSolidSphere(0.15, 15, 15);
			glutSolidCube(0.25);
		}
		glPopMatrix();

		glDisable(GL_BLEND);
	}
	glPopMatrix();
}

void Draw_PlaneObj()
{
	glPushMatrix();
	{
		glColor3d(0.2, 0.2, 0.2);
		glScaled(50, 1, 50);
		glutSolidCube(1);
	}
	glPopMatrix();
}

void Draw_Greed(void)
{
	glColor3f(0.4, 0.4, 0.4);
	glLineWidth(0.5);
	glBegin(GL_LINES);
	for (int i = 0; i < 100; i++) {
		glVertex3f(-50, 0, i - 50);
		glVertex3f(50, 0, i - 50);
	}
	for (int i = 0; i < 100; i++) {
		glVertex3f(i - 50, 0, -50);
		glVertex3f(i - 50, 0, 50);
	}
	glEnd();
}

void Draw_Item()
{
	glPushMatrix();
	{
		glEnable(GL_BLEND);
		glPushMatrix();
		{
			glBlendFunc(GL_SRC_ALPHA, GL_ONE);
			//glColor3f(0.7, 0.2, 0.2);
			glTranslatef(0, 2, 0);
			glColor4f(0, 0.8, 0, 0.8);
			glRotatef(obj_rot, 0, 1, 0);
			glutSolidCube(0.3);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor4f(0.7, 0, 0, 0.5);
			glTranslatef(0, 2, 0);
			glRotatef(obj_rot, 0, 1, 0);
			glRotatef(90, -1, 0, -1);
			glutSolidCube(0.6);
		}
		glPopMatrix();

		glDisable(GL_BLEND);
	}
	glPopMatrix();
}

void Draw_Cage()
{
	glPushMatrix();
	{
		glTranslatef(cageX, cageY, 0);
		glLineWidth(5);
		glBegin(GL_LINE_LOOP);
		{
			glVertex3f(-25, 15, 0);
			glVertex3f(-25, -15, 0);
			glVertex3f(25, -15, 0);
			glVertex3f(25, 15, 0);
		}
		glEnd();
		glLineWidth(1);
	}
	glPopMatrix();
}

void startinit()
{
	switch (startingpoint) {
	case 0:
		Camera_x = 20.0f, Camera_z = 3.5f, Camera_y = 1.75f; // 기본0,5,1.75
		break;
	case 1:
		Camera_x = -18.0f, Camera_z = 3.5f, Camera_y = 1.75f; // 기본0,5,1.75
		break;
	case 2:
		Camera_x = 0.5f, Camera_z = 23.0f, Camera_y = 1.75f; // 기본0,5,1.75
		break;
	case 3:
		Camera_x = 0.5f, Camera_z = -15.0f, Camera_y = 1.75f; // 기본0,5,1.75
		break;
	}

	Level_Minimap = 1;
	speedup = 0;
	Level_Speed = 0;
	item_rand = 8;
	cutoff = 10;
	density = 0.3;
	Level_HP = 0;
	angle = 0;
	deltaAngle = 0;
	Light_rot = 0;
	Bool_Sun = true;
	Bool_PlayGame = true;
}
// Projection

void setProjection(int w, int h)
{
	float ratio;

	ratio = 1.0f*w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h); // 윈도우 뷰포트

	gluPerspective(45, ratio, 0.1, 1000); // 1. 클리핑 공간 설정 원근투영
										  //glTranslatef(0.0, 1.5, -3.0); // 시야 확보

										  //glOrtho(0.0, w, 0.0, h, -1, 1); // 2. 클리핑 공간 설정 : 직각 투영

	glMatrixMode(GL_MODELVIEW);
} // Reshape == 화면 호출 때만 부르는거기에 한 번 만해도 족한 것들

void restorePerspectiveProjection()
{

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void setOrthographicProjection()
{

	glMatrixMode(GL_PROJECTION);

	glPushMatrix();

	glLoadIdentity();

	gluOrtho2D(0, w, h, 0);

	glMatrixMode(GL_MODELVIEW);
}

// 비트맵 String
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
	char *c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}


GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info)
{
	FILE *fp;
	GLubyte *bits;
	int bitsize, infosize;
	BITMAPFILEHEADER header;
	// 바이너리 읽기 모드로 파일을 연다
	if ((fp = fopen(filename, "rb")) == NULL)
		return NULL;
	// 비트맵 파일 헤더를 읽는다.
	if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp)<1) {
		fclose(fp);
		return NULL;
	}
	// 파일이 BMP 파일인지 확인한다.
	if (header.bfType != 'MB') {
		fclose(fp);
		return NULL;
	}
	// BITMAPINFOHEADER 위치로 간다.
	infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
	// 비트맵 이미지 데이터를 넣을 메모리 할당을 한다.
	if ((*info = (BITMAPINFO *)malloc(infosize)) == NULL) {
		fclose(fp);
		exit(0);
		return NULL;
	}
	// 비트맵 인포 헤더를 읽는다.
	if (fread(*info, 1, infosize, fp)<(unsigned int)infosize) {
		free(*info);
		fclose(fp);
		return NULL;
	}
	// 비트맵의 크기 설정
	if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
		bitsize = ((*info)->bmiHeader.biWidth *
		(*info)->bmiHeader.biBitCount + 7) / 8.0 *
		abs((*info)->bmiHeader.biHeight);
	// 비트맵의 크기만큼 메모리를 할당한다.
	if ((bits = (unsigned char *)malloc(bitsize)) == NULL) {
		free(*info);
		fclose(fp);
		return NULL;
	}
	// 비트맵 데이터를 bit(GLubyte 타입)에 저장한다.
	if (fread(bits, 1, bitsize, fp)<(unsigned int)bitsize) {
		free(*info); free(bits);
		fclose(fp);
		return NULL;
	}
	fclose(fp);
	return bits;
}

GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info);


///////////////////////////
//       텍스쳐			 //
///////////////////////////

//GLubyte *LoadDIBitmap(const char *filename, BITMAPINFO **info);
//GLubyte *pBytes; // 데이터를 가리킬 포인터
//BITMAPINFO *info; // 비트맵 헤더 저장할 변수
//GLuint textures[2];
//
//// 텍스쳐 초기화
//void initTextures()
//{
//	glGenTextures(2, textures);
//
//	glBindTexture(GL_TEXTURE_2D, textures[0]);
//	pBytes = LoadDIBitmap("HP.bmp", &info);
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, 81, 82, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
//}
//
//void draw_hp()
//{
//	for (int i = 0; i < hp_max; i++)
//	{
//		glPushMatrix();
//		{
//			glColor3f(1, 1, 1);
//			glTranslatef(-45 + i * 22, -57, 0);
//			glBindTexture(GL_TEXTURE_2D, textures[0]);
//			glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
//			glBegin(GL_POLYGON);
//			{
//				glTexCoord2f(1, 1);
//				glVertex2f(-8, 8);
//				glTexCoord2f(0, 1);
//				glVertex2f(-8, -8);
//				glTexCoord2f(0, 0);
//				glVertex2f(8, -8);
//				glTexCoord2f(1, 0);
//				glVertex2f(8, 8);
//			}
//			glEnd();
//		}
//		glPopMatrix();
//	}
//}