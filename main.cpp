

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
#include<windows.h>


const double PI = 3.141592654;
float x=0, y=0, z=0,x2=0, y2=0, z2=0;
float x4=0,y4=0,z4=0;

float frameNumber = 0;


 void circle_kon()
{


    glBegin(GL_POLYGON);
        for(int i=1;i<180;i++)     //360 kon
        {                                                                          //// y point=sin main point ; x point=cos main point
            glVertex2f(0+1*cos(3.14159*i/180),0+1*sin(3.14159*i/180));       //main point + radius
        }                                                                            //3.14159*i/180   convert degree to radian
        glEnd();

    glFlush();

}

void grass(){
    glColor4f(0.196-x2, 0.658f-y2, 0.180f-z2, 1.00f);
    glBegin(GL_LINES);
    glVertex2f(.60,0);
    glVertex2f(-1.5,2.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.60,0);
    glVertex2f(-0.5,2.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.60,0);
    glVertex2f(1.0,3);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.60,0);
    glVertex2f(1.5,3);
    glEnd();
     glPushMatrix();
    glTranslated(0,0,0);
    glScalef(1.0,1.75,1);
    circle_kon();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,0,0);
    glScalef(1.0,1.75,1);
    circle_kon();
    glPopMatrix();

}
void drawDisk(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}
void drawStar(){

    glColor3f(770.0+x2,770.0+y2,770.0+z2);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f,1.0);
	glVertex2f(0.2f,0.5);
    glVertex2f(-0.2f,0.5);
    glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0.2f,0.5);
	glVertex2f(1.0f,0.5);
    glVertex2f(0.5f,0.0);
	glVertex2f(0.8f,-0.5);
	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.8f,-0.5);
	glVertex2f(-0.5f,0.0f);
	glVertex2f(-1.0f,0.5);
	glVertex2f(-0.2f,0.5);
	glEnd();


}


void drawWheel() {
    int i;
	glColor3f(0,0,0);
	drawDisk(1);
	glColor3f(0.203, 0.133, 0.133);
	drawDisk(0.8);
	glColor3f(0,0,0);
	drawDisk(0.6);
	glRotatef(frameNumber*20,0,0,1);
	glBegin(GL_LINES);
	for (i = 0; i < 15; i++) {
		glVertex2f(0,0);
		glVertex2d(cos(i*2*PI/15), sin(i*2*PI/15));
	}
	glEnd();

}


void drawCar() {

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-3.0f,0.5);
	glVertex2f(3.2f,0.5);
	glVertex2f(3.2f,1.5);
    glVertex2f(2.0f,2);
	glVertex2f(1.0f,3);
	glVertex2f(-1.0f,3);
	glVertex2f(-2.0f,2);
	glVertex2f(-3.0f,2);
	glEnd();
    glColor3f(0.0,0.0,0.);
    glBegin(GL_POLYGON);
	glVertex2f(-1.5f,1.0);
	glVertex2f(1.5f,1.0);
	glVertex2f(1.5f,2.0);
    glVertex2f(0.8f,2.8);
	glVertex2f(-0.8f,2.8);
	glVertex2f(-1.5f,2);
	glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
	glVertex2f(0.0f,2.8);
	glVertex2f(0.0f,1.0);
	glEnd();
    glPushMatrix();
	glTranslatef(-1.5f, 0.8f, 0);
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5f, 0.8f, 0);
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();
}


void drawBwindmill() {
	int i;

	for (i = 0; i < 3; i++) { // Draw 13 rays, with different rotations.
		glRotatef( 120, 0, 0, 1 ); // Note that the rotations accumulate!
		glColor3f(0.584-x2, 0.243-y2, 0.196-z2);
		glBegin(GL_QUADS);
		glVertex2f(0, -0.3);
		glVertex2f(3.0, -0.3);
		glVertex2f(3.0, 0.3);
		glVertex2f(0.0f,0.3);
		glEnd();
			 // Set the line width to be 3 pixels.
    //glLineWidth(3);
	 glColor3f(0,0,0);
	 glBegin(GL_LINES);
	 glVertex2f(0,0);
    glVertex2f(3.2,0.0);
	glEnd();
	//glLineWidth(1);
     glColor3f(0,0,0);
	 glBegin(GL_LINES);
	 glVertex2f(0.8,0.4);
    glVertex2f(0.8,-0.4);
	glEnd();
	     glColor3f(0,0,0);
	 glBegin(GL_LINES);
	 glVertex2f(1.6,0.4);
    glVertex2f(1.6,-0.4);
	glEnd();
	     glColor3f(0,0,0);
	 glBegin(GL_LINES);
	 glVertex2f(2.4,0.4);
    glVertex2f(2.4,-0.4);
	glEnd();
	}
	drawDisk(0.2);
	//glColor3f(0,0,0);
}


void drawWindmill() {
	int i;
	glColor3f(0.8-x2, 0.8-y2, 0.9-z2);
	glBegin(GL_POLYGON);//pillar of the windmill
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
    glPushMatrix();
	glTranslatef(0, 3, 0);
	glRotated(frameNumber * (180.0/106), 0, 0, 1);
	glColor3f(0.137-x4, 0.494-y4, 0.905-z4);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);
		glBegin(GL_POLYGON);//wind of the windmill
		glVertex2f(0,0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f,0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
	glPopMatrix();
    glPushMatrix();
	glTranslatef(0, 3, 0);
	glColor3f(0.427, 0.364, 0.333);
	drawDisk(0.1);
	glPopMatrix();
}
void newHouse(){

	glColor3f(0.501-x2, 0.286-y2, 0.176-z2);//1
    glBegin(GL_TRIANGLES);
	glVertex2f(6.5,4.0);
	glVertex2f(8.0,2.0);
	glVertex2f(5.0,2.0);
	glEnd();
    glColor3f(0.184-x, 0.098-y, 0.380-z);
    glBegin(GL_POLYGON);//2
	glVertex2f(5.0,2.0);
	glVertex2f(8.0,2.0);
	glVertex2f(8.0,0.0);
	glVertex2f(5.0,0.0);
	glEnd();
    glColor3f(0.607-x4, 0.231-y4, 0.231-z4);
    glBegin(GL_POLYGON);//3
	glVertex2f(0.5,3.2);
	glVertex2f(5.5,3.2);
	glVertex2f(5.0,2.0);
	glVertex2f(0.0,2.0);
	glEnd();
    glColor3f(0.282-x, 0.125-y, 0.654-z);
    glBegin(GL_POLYGON);//4
	glVertex2f(0.2,2.0);
	glVertex2f(5.0,2.0);
	glVertex2f(5.0,0.0);
	glVertex2f(0.2,0.0);
	glEnd();
    glColor3f(0.160-x, 0.019-y, 0.019-z);
    glBegin(GL_TRIANGLES);//5
	glVertex2f(5.0,2.0);
	glVertex2f(5.4,3.2);
	glVertex2f(6.5,4.0);
	glEnd();
    glColor3f(0.278-x, 0.482-y, 0.564-z);
    glBegin(GL_POLYGON);//6
	glVertex2f(2.0,0.0);
	glVertex2f(2.25,5.5);
	glVertex2f(3.25,5.5);
	glVertex2f(3.5,0.0);
	glEnd();
    glColor3f(0.419, 0.313, 0.262);
    glBegin(GL_TRIANGLES);//7
	glVertex2f(2.75,6.0);
	glVertex2f(3.25,5.5);
	glVertex2f(2.25,5.5);
	glEnd();
	glColor3f(0+x4,0+y4,0+z4);
    glBegin(GL_POLYGON);//8
	glVertex2f(6.0,1.5);
	glVertex2f(7.0,1.5);
	glVertex2f(7.0,0.5);
	glVertex2f(6.0,0.5);
	glEnd();
    glBegin(GL_POLYGON);//9
	glVertex2f(0.8,1.4);
	glVertex2f(1.2,1.4);
	glVertex2f(1.2,0.6);
	glVertex2f(0.8,0.6);
	glEnd();

	glPushMatrix();
	glTranslated(2.75,6.0,0);
	glRotated(frameNumber*0.4,0,0,1);
	drawBwindmill();
	glPopMatrix();

}

/* Draw three green triangles to form a ridge of hills in the background */
void drawMountain(){

	glColor4f(0.196-x2, 0.658f-y2, 0.180f-z2, 1.00f);
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(1.5f,1.65f);
	glVertex2f(5,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(3,2.1f);
	glVertex2f(7,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0,-1);
	glVertex2f(6,1.2f);
	glVertex2f(10,-1);
	glEnd();


}
/*void drawHouse(){
    glColor3f(0.325, 0.015, 0.027);//1
    glBegin(GL_POLYGON);
	glVertex2f(6.0,4.0);
	glVertex2f(6.8,4.0);
	glVertex2f(8.0,4.2);
	glVertex2f(8.0,7.0f);
	glVertex2f(6.0,7.0f);
	glEnd();
	glColor3f(0.784, 0.819, 0.780);//5
    glBegin(GL_TRIANGLES);
	glVertex2f(6.0,7.0);
	glVertex2f(8.0,7.0);
	glVertex2f(7.0,9.0);
	glEnd();
    glColor3f(0.768, 0.235, 0.784);//2
    glBegin(GL_POLYGON);
	glVertex2f(8.0,4.2);
	glVertex2f(9.5,4.2);
	glVertex2f(9.5,4.8);
	glVertex2f(8.0,4.8f);
	glEnd();
    glColor3f(0.768, 0.235, 0.784);//3
    glBegin(GL_POLYGON);
	glVertex2f(8.0,4.8);
	glVertex2f(9.5,4.8);
	glVertex2f(9.5,5.5);
	glVertex2f(8.0,5.5f);
	glEnd();
	glColor3f(0.149, 0.109, 0.149);
    glBegin(GL_POLYGON);//4
	glVertex2f(8.0,5.5);
	glVertex2f(10.0,5.5);
	glVertex2f(9.3,6.7);
	glVertex2f(8.0,6.7f);
	glEnd();
	glColor3f(0.149, 0.109, 0.149);
    glBegin(GL_POLYGON);//6
	glVertex2f(3.0,6.0);
	glVertex2f(6.0,5.5);
	glVertex2f(6.0,7.0);
	glVertex2f(4.0,7.3f);
	glEnd();
	glColor3f(0.768, 0.235, 0.784);
    glBegin(GL_POLYGON);//7
	glVertex2f(2.9,5.4);
	glVertex2f(6.0,5.0);
	glVertex2f(6.0,5.5);
	glVertex2f(3.0,6.0);
	glEnd();
	glColor3f(0.768, 0.235, 0.784);
    glBegin(GL_POLYGON);//7
	glVertex2f(2.8,5.0);
	glVertex2f(6.0,4.0);
	glVertex2f(6.0,5.0);
	glVertex2f(3.0,6.0);
	glEnd();
    glPushMatrix();
	glTranslated(7.0,7.0,0);
	glRotated(-frameNumber*0.7,0,0,1);
	drawSun();
	glPopMatrix();



}*/

/*
 * This function is called when the image needs to be redrawn.
 * It is installed by main() as the GLUT display function.
 * It draws the current frame of the animation.
 */
void display() {

	glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with blue.
	glClearColor(0.474-x4, 0.717-y4, 0.423-z4, 1);
	glLoadIdentity();


    glColor3f(1-x4,1-y4,1-z4);//creat a white background
	glBegin(GL_QUADS);
    glVertex2f(0.0,5.8f);
	glVertex2f(0.0,11.0f);
	glVertex2f(15.0,11.0f);
	glVertex2f(15.0,5.8f);
	glEnd();

	if(frameNumber>700){
    //draw star
    glPushMatrix();
	glTranslated(4.5,9.7,0);
	glScaled(0.25,0.25,1);
	drawStar();
	glPopMatrix();
	    glPushMatrix();
	glTranslated(6.5,9.8,0);
	glScaled(0.25,0.25,1);
	drawStar();
	glPopMatrix();
    glPushMatrix();
	glTranslated(8.5,9.2,1);
	glScaled(0.25,0.25,1);
	drawStar();
	glPopMatrix();
    glPushMatrix();
	glTranslated(9.5,10,0);
	glScaled(0.25,0.25,1);
	drawStar();
	glPopMatrix();

    glPushMatrix();
	glTranslated(7.5,9.5,1);
	glScaled(0.25,0.25,1);
	drawStar();
	glPopMatrix();

    glPushMatrix();
	glTranslated(2.5,9.5,1);
	glScaled(0.25,0.25,1);
	drawStar();
	glPopMatrix();

    glPushMatrix();
	glTranslated(11.5,9.5,1);
	glScaled(0.25,0.25,1);
	drawStar();
	glPopMatrix();

    glPushMatrix();
	glTranslated(14.5,9.6,1);
	glScaled(0.25,0.25,1);
	drawStar();
	glPopMatrix();

    glPushMatrix();
	glTranslated(1.0,9.75,1);
	glScaled(0.25,0.25,1);
	drawStar();
	glPopMatrix();
	}

    /*Draw the sun*/
    if(frameNumber<390){
    glColor3f(0.905, 0.866, 0.074);
	glPushMatrix();
	glTranslated(2.0,9-(frameNumber/180),0);
	//glRotated(-frameNumber*0.7,0,0,1);
	drawDisk(1);
	glPopMatrix();
    }




    glPushMatrix();//draw mountain1
	glTranslated(0.0,6.8,0);
	glScaled(0.5,1.0,1);
	drawMountain();
	glPopMatrix();

	    glPushMatrix();//draw mountain2
	glTranslated(5.0,6.8,0);
	glScaled(0.8,1.0,1);
	drawMountain();
	glPopMatrix();
        glPushMatrix();//draw mountain3
	glTranslated(10.0,6.8,0);
	glScaled(0.8,1.0,1);
	drawMountain();
	glPopMatrix();


	//draw grass
    glPushMatrix();
	glTranslated(3.0,2.8,0);
	glScaled(0.2,0.2,1);
	grass();
	glPopMatrix();

    glPushMatrix();
	glTranslated(12.0,1.8,0);
	glScaled(0.2,0.2,1);
	grass();
	glPopMatrix();

    glPushMatrix();
	glTranslated(13.0,3.8,0);
	glScaled(0.1,0.1,1);
	grass();
	glPopMatrix();

    glPushMatrix();
	glTranslated(10.0,2.3,0);
	glScaled(0.2,0.2,1);
	grass();
	glPopMatrix();

    glPushMatrix();
	glTranslated(1.0,3.8,0);
	glScaled(0.1,0.1,1);
	grass();
	glPopMatrix();

    glPushMatrix();
	glTranslated(4.8,4.8,0);
	glScaled(0.08,0.08,1);
	grass();
	glPopMatrix();

    glPushMatrix();
	glTranslated(0.5,4.8,0);
	glScaled(0.09,0.09,1);
	grass();
	glPopMatrix();
    glPushMatrix();
	glTranslated(14.5,5.5,0);
	glScaled(0.07,0.07,1);
	grass();
	glPopMatrix();


	/* Draw a bluish-gray rectangle to represent the road. */

	glColor3f(0.4-x, 0.4-y, 0.5-z2);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,0.0);
	glVertex2f(15.0,0.0);
	glVertex2f(15,1.6f);
	glVertex2f(0,1.6f);
	glEnd();

	/* Draw a white line to represent the stripe down the middle
	 * of the road. */

	glLineWidth(3);  // Set the line width to be 3 pixels.
	glColor3f(1-x4,1-y4,1-z4);
	glBegin(GL_LINES);
	glVertex2f(0,.8);
	glVertex2f(15,.8);
	glEnd();
	glLineWidth(1);  // Reset the line width to be 1 pixel.



	glPushMatrix();
	glTranslated(2.5,5,0);
	glScaled(0.6,0.6,1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(12.5,2.6,0);
	glScaled(1.6,1.6,1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(12.0,5.0,0);
	glScaled(0.7,0.7,1);
	drawWindmill();
	glPopMatrix();


	/*Draw the house*/
    glPushMatrix();
	glTranslated(5.0,3.8,0);
	glScaled(0.7,0.7,1.0);
	newHouse();
	glPopMatrix();





	/* Draw the car  */

	glPushMatrix();
	glTranslated(frameNumber/42, 0, 0);

	glScaled(0.5,0.5,1);
	drawCar();
	glPopMatrix();



	glutSwapBuffers();

}  // end display

/*
 * This function is set as the glutTimerFunc to drive the animation
 */
void doFrame(int v) {
    frameNumber++;
    x4=x4+0.001;
    y4=y4+0.001;
    z4=z4+0.001;

    x2=x2+0.0004;
    y2=y2+0.0004;
    z2=z2+0.0004;

    x2=x2+0.0002;
    y2=y2+0.0002;
    z2=z2+0.0002;

       if(frameNumber>1000){
        frameNumber=0;
         x=0, y=0, z=0, x2=0.00, y2=0.00, z2=0.00;
         x4=0,y4=0,z4=0;
        PlaySound("countryroad123.wav", NULL, SND_ASYNC|SND_FILENAME);
    }



    glutPostRedisplay();

    glutTimerFunc(25,doFrame,0);//after each 24 mill sec the loop wil continue
}


void init() {
	glClearColor(0.196, 0.658, 0.180, 1);
		// The next three lines set up the coordinates system.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();////replace the matrix with current matrix
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glOrtho(0, 15, -1, 11, -1, 1);//(minX,maxX,minY,maxY,minZ,maxZ)
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);

    glutInitWindowSize(520,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow(".....Country road.....");
    init();
    glutDisplayFunc(display);
    PlaySound("countryroad123.wav", NULL, SND_ASYNC|SND_FILENAME);
    glutTimerFunc(200,doFrame,0);//after 200 mill sec the program will enter into the doFrame function
    //PlaySound("countryroad123.wav", NULL, SND_ASYNC|SND_FILENAME);
    glutMainLoop();
    return 0;
}
