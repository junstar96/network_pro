#include "resource.h"

//////////////////////////////////////
//			resource.cpp			//
//									//
//	���ӿ��� Ȱ��Ǵ� resource����	//
//	��Ƴ��� cpp�Դϴ�.				//
//	1. �ʿ��� ���Ǵ� Obj			//
//	2. ����(Projection)���� �Լ�		//
//	3. ��Ʈ��(�۾�), �ؽ���(�׸�)		//
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
	glLineWidth(1); // �� ��ġ-
}

void Draw_PlayerObj()
{
	glPushMatrix();
	{
		glTranslatef(0, 0.5, 3);
		glColor3f(1, 8, 1);
		glScalef(0.4, 0.75, 0.4);

		glBegin(GL_QUADS);
		{
			//����
			glColor3f(0.0f, 0.0f, 1.0f);// Blue
			glVertex3f(1, 1, 1);
			glColor3f(0.0f, 1.0f, 0.0f);// Green
			glVertex3f(1, 1, -1);
			glColor3f(1.0f, 0.0f, 0.0f);// Red
			glVertex3f(-1, 1, -1);
			glColor3f(1.0f, 1.0f, 0.0f);// Yellow
			glVertex3f(-1.0, 1.0, 1.0f);

			//�޸�
			glColor3f(0.0f, 1.0f, 0.0f);// Green
			glVertex3f(1, 1, -1);
			glColor3f(0.0f, 0.0f, 0.0f);// Black
			glVertex3f(1, -1, -1);
			glColor3f(1.0f, 1.0f, 1.0f);// White
			glVertex3f(-1, -1, -1);
			glColor3f(1.0f, 0.0f, 0.0f);// Red
			glVertex3f(-1, 1, -1);

			//�Ʒ���
			glColor3f(1.0f, 0.0, 1.0f);// Magenta
			glVertex3f(-1, -1, 1);
			glColor3f(1.0f, 1.0f, 1.0f);// White
			glVertex3f(-1, -1, -1);
			glColor3f(0.0f, 0.0f, 0.0f);// Black
			glVertex3f(1, -1, -1);
			glColor3f(0.0f, 1.0f, 1.0f);// Cyan
			glVertex3f(1, -1, 1);

			//�޸�
			glColor3f(1.0f, 0.0f, 0.0f);// Red
			glVertex3f(-1, 1, -1);
			glColor3f(1.0f, 1.0f, 1.0f);// White
			glVertex3f(-1, -1, -1);
			glColor3f(1.0f, 0.0, 1.0f);// Magenta
			glVertex3f(-1, -1, 1);
			glColor3f(1.0f, 1.0f, 0.0f);// Yellow
			glVertex3f(-1.0, 1.0, 1.0f);

			//������

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
	player.SetPosition();

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
	isPlayGame = true;
}
// Projection

void setProjection(int w, int h)
{
	float ratio;

	ratio = 1.0f*w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h); // ������ ����Ʈ

	gluPerspective(45, ratio, 0.1, 1000); // 1. Ŭ���� ���� ���� ��������
										  //glTranslatef(0.0, 1.5, -3.0); // �þ� Ȯ��

										  //glOrtho(0.0, w, 0.0, h, -1, 1); // 2. Ŭ���� ���� ���� : ���� ����

	glMatrixMode(GL_MODELVIEW);
} // Reshape == ȭ�� ȣ�� ���� �θ��°ű⿡ �� �� ���ص� ���� �͵�

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

// ��Ʈ�� String
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
	// ���̳ʸ� �б� ���� ������ ����
	if ((fp = fopen(filename, "rb")) == NULL)
		return NULL;
	// ��Ʈ�� ���� ����� �д´�.
	if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp)<1) {
		fclose(fp);
		return NULL;
	}
	// ������ BMP �������� Ȯ���Ѵ�.
	if (header.bfType != 'MB') {
		fclose(fp);
		return NULL;
	}
	// BITMAPINFOHEADER ��ġ�� ����.
	infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
	// ��Ʈ�� �̹��� �����͸� ���� �޸� �Ҵ��� �Ѵ�.
	if ((*info = (BITMAPINFO *)malloc(infosize)) == NULL) {
		fclose(fp);
		exit(0);
		return NULL;
	}
	// ��Ʈ�� ���� ����� �д´�.
	if (fread(*info, 1, infosize, fp)<(unsigned int)infosize) {
		free(*info);
		fclose(fp);
		return NULL;
	}
	// ��Ʈ���� ũ�� ����
	if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
		bitsize = ((*info)->bmiHeader.biWidth *
		(*info)->bmiHeader.biBitCount + 7) / 8.0 *
		abs((*info)->bmiHeader.biHeight);
	// ��Ʈ���� ũ�⸸ŭ �޸𸮸� �Ҵ��Ѵ�.
	if ((bits = (unsigned char *)malloc(bitsize)) == NULL) {
		free(*info);
		fclose(fp);
		return NULL;
	}
	// ��Ʈ�� �����͸� bit(GLubyte Ÿ��)�� �����Ѵ�.
	if (fread(bits, 1, bitsize, fp)<(unsigned int)bitsize) {
		free(*info); free(bits);
		fclose(fp);
		return NULL;
	}
	fclose(fp);
	return bits;
}

//GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info);


///////////////////////////
//       �ؽ���			 //
///////////////////////////

//GLubyte *LoadDIBitmap(const char *filename, BITMAPINFO **info);
//GLubyte *pBytes; // �����͸� ����ų ������
//BITMAPINFO *info; // ��Ʈ�� ��� ������ ����
//GLuint textures[2];
//
//// �ؽ��� �ʱ�ȭ
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