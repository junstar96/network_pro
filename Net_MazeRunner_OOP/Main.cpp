#include "Main.h"
#include "stdafx.h"
#include "Time.h"
#include "Input.h"
#include "RenderScene.h"
#include "Network.h"

void Reshape(int w1, int h1)
{
	PlaySound(TEXT(SOUND_FILE_NAME_BGM_1), NULL, SND_ASYNC | SND_SYNC);

	if (h1 == 0)
		h1 = 1;

	w = w1;
	h = h1;

	glutSetWindow(subWindow1);
	glutPositionWindow(border, border);
	glutReshapeWindow(w - 2 * border, h / 2 - border * 3 / 2);
	setProjection(w - 2 * border, h / 2 - border * 3 / 2);

	glutSetWindow(subWindow2);
	glutPositionWindow(border, (h + border) / 2);
	glutReshapeWindow(w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);
	setProjection(w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);

	glutSetWindow(subWindow3);
	glutPositionWindow((w + border) / 2, (h + border) / 2);
	glutReshapeWindow(w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);
	setProjection(w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);
}



int main(int argc, char **argv) {

	for (int i = 0; i < B_SIZE; i++)
	{
		for (int j = 0; j < B_SIZE; j++)
		{
			Collision_Maze[i][j].max_x += i*1.1;
			Collision_Maze[i][j].max_z += j*1.1;
			Collision_Maze[i][j].min_x += i*1.1;
			Collision_Maze[i][j].min_z += j*1.1;
		}
	} // 블럭 초기화
	srand(time(NULL));

	player.SetPosition();
	
	hWrite_Event = CreateEvent(NULL, FALSE, TRUE, NULL);
	hRead_Event = CreateEvent(NULL, FALSE, FALSE, NULL);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	mainWindow = glutCreateWindow("Net_3DMazeRunner");
	glutTimerFunc(timef, TimerFunction, 60);

	// 윈도우
	glutDisplayFunc(renderScene);
	glutReshapeFunc(Reshape);
	glutIdleFunc(DrawScene);
	init(); // 키보드/ 마우스

	// 서브윈도우
	subWindow1 = glutCreateSubWindow(mainWindow, border, border, w - 2 * border, h / 2 - border * 3 / 2);
	glutDisplayFunc(RenderSceneW1);
	init();

	subWindow2 = glutCreateSubWindow(mainWindow, border, (h + border) / 2, w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);
	glutDisplayFunc(RenderSceneW2);
	init();

	subWindow3 = glutCreateSubWindow(mainWindow, (w + border) / 2, (h + border) / 2, w / 2 - border * 3 / 2, h / 2 - border * 3 / 2);
	glutDisplayFunc(RenderSceneW3);
	init();

	glutMainLoop();

	return 1;
}