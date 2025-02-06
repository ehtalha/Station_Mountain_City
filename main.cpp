
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>>
#include <mmsystem.h> //sound

#include<cstdio>    //C Standard I/O Library

#include <GL/gl.h>

///................................Frame 2...............................................///




# define PI           3.14159265358979323846

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. Text */
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}


bool flag = false;
bool flag1 = false;

GLfloat i = 0.0f;

GLfloat s3BigP1 = -2.5f;  //x
GLfloat s3BigP1Speed1 = 0.03f;

GLfloat s3BigP1Y = 1.0f; //y
GLfloat s3BigP1SpeedY = 0.02f;

GLfloat runway1 = 0.0f;
GLfloat runSpeed1 = 0.02f;

GLfloat runway22 = 0.2f;
GLfloat runSpeed2 = 0.02f;

GLfloat p3Cloud = 0.0f;
GLfloat p3CloudSpeed = 0.015f;

GLfloat p3Cloudfly = 0.0f;
GLfloat p3CloudflySpeed = 0.01f;

GLfloat p2Cloud = 0.0f;
GLfloat p2CloudSpeed = 0.015f;

GLfloat rotation = 0.0f;

GLfloat s3smallp2 = 1.6f;
GLfloat s3smallp2Speed2 = 0.025f;
//s3smallp2

GLfloat p2Plane1 = 0.0f;
GLfloat p2Plane1Sp1 = 0.03f;

GLfloat p2Plane2 = 2.0f;
GLfloat p2Plane1Sp2 = 0.03f;

GLfloat p1Pane1 = 0.0f;
GLfloat p1PlaneSp1 = 0.025f;

GLfloat bus3 = 0.0f;
GLfloat busSpeed1 = 0.02f;

GLfloat pickupPosition = -0.5f;
GLfloat pickupSpeed = 0.012f;

GLfloat thunderposition = 0.5f;
GLfloat thunderSpeed = 0.15f;

GLfloat thunderposition1 = 3.0f;
GLfloat thunderSpeed1 = 0.15f;


void update3(int value){


    flag = true;

    if(s3smallp2 <-2.6)
        s3smallp2 =2.5f;
    s3smallp2 -= s3smallp2Speed2;

    if(s3BigP1 >2.6)
        s3BigP1 =-3.0f;
    else if(s3BigP1 >0.0)
        s3BigP1 = 0.0;
    s3BigP1 += s3BigP1Speed1;

    if(s3BigP1Y <-2.6)
        s3BigP1Y =1.0;
    else if(s3BigP1Y <-0.7)
        s3BigP1Y = -0.7;
    s3BigP1Y -= s3BigP1SpeedY;

    if(runway1 <-2.6)
        runway1 =2.0;
    //else if(runway1 <-2.0)
        //runway1 = -2.0;
    //runway1 -= runSpeed1;
    runway1 -= runSpeed1;

    if(runway22 <-4.6)
        runway22 =2.0;
    //else if(runway22 <-2.3)
        //runway22 = -2.3;
    //runway22 -= runSpeed2;
    runway22 -= runSpeed2;

    if(p3Cloud <-2.6)
        p3Cloud =2.0;
    else if(p3Cloud >-0.1)
        p3Cloud = -0.1;
    //else if(p3Cloud <-1.8)
        //p3Cloud = -1.8;
    //p3Cloud -= p3CloudSpeed;
    p3Cloud -= p3CloudSpeed;

    if(p3Cloudfly <-3.6)
        p3Cloudfly =1.5;
    //else if(p3Cloudfly >-0.1)
        //p3Cloudfly = -0.1;
    //else if(p3Cloudfly <-1.8)
        //p3Cloudfly = -1.8;
    //p3Cloud -= p3CloudSpeed;
    p3Cloudfly -= p3CloudflySpeed;

    glutPostRedisplay();
    glutTimerFunc(60, update3, 0);
}

void displayCover() {
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glMatrixMode(GL_PROJECTION); // setting up the projection matrix
    glLoadIdentity();   //reset
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    //page border
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(-0.4, 0.9);
    glVertex2f(0.4, 0.9);
    glVertex2f(0.4, -0.9);
    glVertex2f(-0.4, -0.9);

    glEnd();



    //uni name
    glPushMatrix();
    glTranslatef(-0.01f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.347826713588f, 0.8116267414833f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University -Bangladesh (AIUB)");
    glPopMatrix();



    //course name
    glPushMatrix();
    glTranslatef(+0.01f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.1690949430827f, 0.6779878488577f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Course : Computer Graphics");
    glPopMatrix();

    //section
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0707104822541f, 0.6173174313468f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Section : K");

    //project name
    glPushMatrix();
    glTranslatef(+0.01f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.2150076914694f, 0.5402496036977f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Project Name : Visualization of Railway Station");
    glPopMatrix();

    //group number
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0682508707334f, 0.4877778912557f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Group : 10");

    //Submitted to
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0790214813468f, 0.4127290449519f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Submitted to :");

    //MAHFUJUR RAHMAN
    glPushMatrix();
    glTranslatef(+0.03f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.1612865259168f, 0.3559436165065f, 0.0f, GLUT_BITMAP_HELVETICA_18, "NOBORANJAN DEY");
    glPopMatrix();

    //ASSISTANT PROFESSOR
    glPushMatrix();
    glTranslatef(+0.02f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.1351389049429f, 0.2976143081801f, 0.0f, GLUT_BITMAP_HELVETICA_12, "ASSISTANT PROFESSOR");
    glPopMatrix();

    //FACULTY
    glPushMatrix();
    glTranslatef(-0.09f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0798266298058f, 0.2483360994216f, 0.0f, GLUT_BITMAP_HELVETICA_12, "FACULTY OF SCIENCE AND TECHNOLOGY");
    glPopMatrix();

    //DEPARTMENT OF COMPUTER SCIENCE
    glPushMatrix();
    glTranslatef(+0.045f, 0.02f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.1995022796479f, 0.1859840801762f, 0.0f, GLUT_BITMAP_HELVETICA_12, "DEPARTMENT OF COMPUTER SCIENCE");
    glPopMatrix();

    //Submitted by:
    glPushMatrix();
    glTranslatef(0.0f, -0.1f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0793856994797f, 0.1328747868973f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Submitted by:");

    //table

    //border
    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.86f, 0.86f);
    glVertex2f(-0.3, 0.1);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.3, -0.3);
    glVertex2f(-0.3, -0.3);
    glEnd();

    //2nd row
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.83f, 0.83f);
    glVertex2f(-0.3, 0.05);
    glVertex2f(0.3, 0.05);
    glVertex2f(0.3, -0.03);
    glVertex2f(-0.3, -0.03);
    glEnd();

    //4th row
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.83f, 0.83f);
    glVertex2f(-0.3, -0.1);
    glVertex2f(0.3, -0.1);
    glVertex2f(0.3, -0.17);
    glVertex2f(-0.3, -0.17);
    glEnd();

    //6th row
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.83f, 0.83f);
    glVertex2f(-0.3, -0.24);
    glVertex2f(0.3, -0.24);
    glVertex2f(0.3, -0.3);
    glVertex2f(-0.3, -0.3);
    glEnd();


    //serial
    glPushMatrix();
    glTranslatef(-0.01,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.28f, 0.08f, 0.0f, GLUT_BITMAP_HELVETICA_12, "SERIAL NO.");
    glPopMatrix();

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f, 0.08f, 0.0f, GLUT_BITMAP_HELVETICA_12, "NAME");
    glPopMatrix();


    //id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f, 0.08f, 0.0f, GLUT_BITMAP_HELVETICA_12, "ID");

    //Contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f, 0.08f, 0.0f, GLUT_BITMAP_HELVETICA_12, "CONTRIBUTION");




    //EMDADUL HAQUE TALHA

    //serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.27f, 0.02f, 0.0f, GLUT_BITMAP_HELVETICA_12, "14");

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f, 0.02f, 0.0f, GLUT_BITMAP_HELVETICA_12, "EMDADUL HAQUE TALHA");
    glPopMatrix();

    //Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f, 0.02f, 0.0f, GLUT_BITMAP_HELVETICA_12, "22-47402-2");

    //contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f, 0.02f, 0.0f, GLUT_BITMAP_HELVETICA_12, "20%");



    //Md. RAHIDUL ISLAM
    //serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.27f, -0.06f, 0.0f, GLUT_BITMAP_HELVETICA_12, "43");

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f, -0.06f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Md RAHIDUL ISLAM");
    glPopMatrix();

    //Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f, -0.06f, 0.0f, GLUT_BITMAP_HELVETICA_12, "23-51269-1");

    //contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f, -0.06f, 0.0f, GLUT_BITMAP_HELVETICA_12, "20%");



    //JEBA SHANJIDA
    //serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.27f, -0.13f, 0.0f, GLUT_BITMAP_HELVETICA_12, "8");

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f, -0.13f, 0.0f, GLUT_BITMAP_HELVETICA_12, "JEBA SHANJIDA");
    glPopMatrix();

    //Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f, -0.13f, 0.0f, GLUT_BITMAP_HELVETICA_12, "22-46590-1");

    //contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f, -0.13f, 0.0f, GLUT_BITMAP_HELVETICA_12, "20%");



    //TONIMA ISLAM
    //serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.27f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_12, "25");

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_12, "TONIMA ISLAM");
    glPopMatrix();

    //Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_12, "22-48325-3");

    //contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_12, "20%");



    //MAHINUR BINTE KARIM
    //serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.27f,  -0.275f, 0.0f, GLUT_BITMAP_HELVETICA_12, "23");

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f,  -0.275f, 0.0f, GLUT_BITMAP_HELVETICA_12, "MAHINUR BINTE KARIM");
    glPopMatrix();

    //Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f,  -0.275f, 0.0f, GLUT_BITMAP_HELVETICA_12, "22-48086-2");

    //contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f,  -0.275f, 0.0f, GLUT_BITMAP_HELVETICA_12, "20%");

    glPopMatrix();




    //Click the right button of your mouse to continue
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.35f, -0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "[ Click the LEFT mouse button (LMB) to continue ]"); //-0.25



     glFlush(); // Render now
}

void displayNavigation() {
    glClearColor(0.4f, 0.57f, 0.33f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    //Navigation
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.0f, 0.9f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Navigation");



    //Click "s" to view page 1
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.05f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Click '1' to view Scene 1");

    //Click "h" to view page 2
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.05f, 0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Click '2' to view Scene 2");

    //Click "c" to view page 3
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.05f, 0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Click '3' to view Scene 3");

    //Click the right button of your mouse to visit cover page
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.25f, -0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "[ Click the RIGHT mouse button to view Cover Page ]");



    glPopMatrix();



     glFlush(); // Render now
}

void clouds1(float r, float s)
{

    glPushMatrix();
    //glTranslatef(p3Cloud,0.0f, 0.0f);

    glTranslatef(r,s, 0.0f);

    //cloud
    int i;

    GLfloat x=2.0664666559629f;
    GLfloat y=0.384679318014f;
    GLfloat radius =0.05f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x1=2.1249747089483f;
    GLfloat y1=0.3731062965444f;
    GLfloat radius1 =0.04f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x2=2.0086015486148f;
    GLfloat y2=0.362176220712f;
    GLfloat radius2 =0.045f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2 + (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x3=1.9610235714619f;
    GLfloat y3=0.3512461448795f;
    GLfloat radius3 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x4=2.1641943928175f;
    GLfloat y4=0.3692486227212f;
    GLfloat radius4 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
                    y4 + (radius4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

}


void clouds4(float p, float p1)
{

    glPushMatrix();
    glTranslatef(p3Cloud,0.0f, 0.0f);

    glTranslatef(p,p1, 0.0f);

    //cloud
    int i;

    GLfloat x=2.0664666559629f;
    GLfloat y=0.384679318014f;
    GLfloat radius =0.05f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x1=2.1249747089483f;
    GLfloat y1=0.3731062965444f;
    GLfloat radius1 =0.04f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x2=2.0086015486148f;
    GLfloat y2=0.362176220712f;
    GLfloat radius2 =0.045f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2 + (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x3=1.9610235714619f;
    GLfloat y3=0.3512461448795f;
    GLfloat radius3 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x4=2.1641943928175f;
    GLfloat y4=0.3692486227212f;
    GLfloat radius4 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
                    y4 + (radius4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

}


void buildings()
{

    glPushMatrix();
    glTranslatef(p3Cloud,0.0f, 0.0f);

    //outside building 1
    glBegin(GL_POLYGON);
    glColor3f(0.51f, 0.51f, 0.5f);
    glVertex2f(2.5052392914906, -0.0873145496797);
    glVertex2f(3.0064008476205, -0.0873145496797);
    glVertex2f(3.0064008476205, -0.3241466478862);
    glVertex2f(2.5025782566793, -0.32503365949);

    glEnd();

    //outside building 2
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.51f, 0.51f);
    glVertex2f(2.4839856407212, 0.3302674900268);
    glVertex2f(2.4834222584246, 0.4142114522174);
    glVertex2f(2.3938444732682, 0.4130846876242);
    glVertex2f(2.3966613847511, 0.3297041077302);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.69f, 0.3f, 0.29f);
    glVertex2f(2.5161856718456, 0.3387663872012);
    glVertex2f(2.1077198411145, 0.3367505969413);
    glVertex2f(2.1077198411145, -0.3451745894677);
    glVertex2f(2.5197424188891, -0.3334588040066);

    glEnd();

    //windows
    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.2f, 0.0f);

    //windows down
    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.4f, 0.0f);

    //windows down 2
    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.1, 0.27);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);

    //door
    glBegin(GL_POLYGON);
    glColor3f(0.43, 0.23, 0);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.0276823093388);
    glVertex2f(2.2424845752272, 0.0276823093388);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPopMatrix();

    glPopMatrix();

    //outside building 3
    glBegin(GL_POLYGON);
    glColor3f(0.51, 0.51, 0.0);
    glVertex2f(2.1164372365763, 0.0836921310177);
    glVertex2f(1.6830307269187, 0.085464754779);
    glVertex2f(1.6723949843504, -0.3142619034124);
    glVertex2f(2.1164372365763, -0.3178071509351);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.41, 0.63, 0.51);
    glVertex2f(2.1091483555903, 0.0518647690943);
    glVertex2f(1.6718629906373, 0.0559276825799);
    glVertex2f(1.6723418186648, -0.0016060226348);
    glVertex2f(2.1091483555903, 0.0000711422815);

    glEnd();

    glPushMatrix();
    glTranslatef(0.035f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(2.0439384580487, -0.0220003025443);
    glVertex2f(1.7126865194035, -0.0218966596596);
    glVertex2f(1.7126865194035, -0.1747677554869);
    glVertex2f(2.0439384580487, -0.1729629698979);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.69, 0.63);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPushMatrix();
    glTranslatef(0.08f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.69, 0.63);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.16f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.69, 0.63);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.24f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.69, 0.63);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.71, 0.82, 0.76);
    glVertex2f(2.0421066212766, -0.1845469483218);
    glVertex2f(1.7159203616344, -0.1845469483218);
    glVertex2f(1.7159203616344, -0.3243908979676);
    glVertex2f(2.0421066212766, -0.3077202938813);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.04f, -0.17f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.17, 0.24, 0.2);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPushMatrix();
    glTranslatef(0.08f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.17, 0.24, 0.2);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.16f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.17, 0.24, 0.2);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.24f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.17, 0.24, 0.2);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glPopMatrix();

    //outside building 4 upper
    glBegin(GL_POLYGON);
    glColor3f(0.41f, 0.51f, 0.51f);
    glVertex2f(1.586454465712, 0.2214850289479);
    glVertex2f(1.3580673518243, 0.2214850289479);
    glVertex2f(1.3611398242084, 0.1170209678872);
    glVertex2f(1.5874786231734, 0.113948495503);

    glEnd();

    //window left
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.6f, 0.7f);
    glVertex2f(1.4648153291931, 0.1849529650144);
    glVertex2f(1.4229109846961, 0.1851794749847);
    glVertex2f(1.4242700445176, 0.1407835208149);
    glVertex2f(1.4654948591039, 0.1410100307851);

    glEnd();

    glPushMatrix();
    glTranslatef(0.09f, 0.04f, 0.0f);
    //window left
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.4648153291931, 0.1849529650144);
    glVertex2f(1.4229109846961, 0.1851794749847);
    glVertex2f(1.4242700445176, 0.1407835208149);
    glVertex2f(1.4654948591039, 0.1410100307851);

    glEnd();
    glPopMatrix();


    //lower
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.67f, 0.38f);
    glVertex2f(1.6950151566183, 0.1293108574237);
    glVertex2f(1.2341442989973, 0.1303350148851);
    glVertex2f(1.2249268818449, -0.3336083151201);
    glVertex2f(1.6950151566183, -0.3243908979676);

    glEnd();

    //window left
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.4367467413409, 0.0721655944815);
    glVertex2f(1.3235934117274, 0.0721655944815);
    glVertex2f(1.3221730770461, -0.036726731088);
    glVertex2f(1.438640520916, -0.0372001759818);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.055f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.18f, 0.0f, 0.0f);
    //window right
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.4367467413409, 0.0721655944815);
    glVertex2f(1.3235934117274, 0.0721655944815);
    glVertex2f(1.3221730770461, -0.036726731088);
    glVertex2f(1.438640520916, -0.0372001759818);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.055f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    //lower window set
    glPushMatrix();
    glTranslatef(0.0f, -0.15f, 0.0f);

    //window left
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.4367467413409, 0.0721655944815);
    glVertex2f(1.3235934117274, 0.0721655944815);
    glVertex2f(1.3221730770461, -0.036726731088);
    glVertex2f(1.438640520916, -0.0372001759818);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.055f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.18f, 0.0f, 0.0f);
    //window right
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.4367467413409, 0.0721655944815);
    glVertex2f(1.3235934117274, 0.0721655944815);
    glVertex2f(1.3221730770461, -0.036726731088);
    glVertex2f(1.438640520916, -0.0372001759818);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.055f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    //door
    glBegin(GL_POLYGON);
    glColor3f(0.47, 0.46, 0.48);
    glVertex2f(1.5836547658145, -0.2032075233223);
    glVertex2f(1.3588049950672, -0.2032075233223);
    glVertex2f(1.3605412867332, -0.3507923149325);
    glVertex2f(1.5888636408125, -0.3481878774335);

    glEnd();

    //outside building 5
    glBegin(GL_POLYGON);
    glColor3f(0.51, 0., 0.51);
    glVertex2f(1.2454357137285, 0.2484939878635);
    glVertex2f(1.2597513275161, 0.2784266348739);
    glVertex2f(1.2571484886456, 0.3213734762368);
    glVertex2f(0.9819800094641, 0.3193025876967);
    glVertex2f(0.9799461489401, -0.3215277247703);
    glVertex2f(1.2506413914694, -0.3202263053351);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.64, 0.51, 0.76);
    glVertex2f(1.2454357137285, 0.2484939878635);
    glVertex2f(1.2554955734245, 0.2695282399551);
    glVertex2f(0.9864532461163, 0.2693166988273);
    glVertex2f(0.9865353972053, 0.2462361437231);

    glEnd();

    //window upper
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1389882460371, 0.0873535679951);
    glVertex2f(1.1381607145674, 0.2127245856557);
    glVertex2f(1.0621939281718, 0.2111541364441);
    glVertex2f(1.0636828822939, 0.0873535679951);
    glVertex2f(1.0545800361271, 0.0865260365254);
    glVertex2f(1.0554075675968, 0.0650102183131);
    glVertex2f(1.1489186236736, 0.0654239840479);
    glVertex2f(1.1476773264691, 0.08776733373);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.51, 0.59, 0.76);
    glVertex2f(1.1302991656052, 0.2015529108147);
    glVertex2f(1.0711306655212, 0.2015529108147);
    glVertex2f(1.0733697449682, 0.0877605621442);
    glVertex2f(1.1311266970749, 0.0885948651997);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1027278458891, 0.2059880507902);
    glVertex2f(1.097899618681, 0.2062562856351);
    glVertex2f(1.0997772625953, 0.084477666054);
    glVertex2f(1.1059466640278, 0.084477666054);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1343795575864, 0.141611688016);
    glVertex2f(1.0689302554327, 0.141611688016);
    glVertex2f(1.0681826603238, 0.1373026182134);
    glVertex2f(1.1346477924313, 0.136783460808);

    glEnd();

    glPushMatrix();
    glTranslatef(0.0f, -0.18f, 0.0f);
    //window down
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1389882460371, 0.0873535679951);
    glVertex2f(1.1381607145674, 0.2127245856557);
    glVertex2f(1.0621939281718, 0.2111541364441);
    glVertex2f(1.0636828822939, 0.0873535679951);
    glVertex2f(1.0545800361271, 0.0865260365254);
    glVertex2f(1.0554075675968, 0.0650102183131);
    glVertex2f(1.1489186236736, 0.0654239840479);
    glVertex2f(1.1476773264691, 0.08776733373);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.51, 0.59, 0.76);
    glVertex2f(1.1302991656052, 0.2015529108147);
    glVertex2f(1.0711306655212, 0.2015529108147);
    glVertex2f(1.0733697449682, 0.0877605621442);
    glVertex2f(1.1311266970749, 0.0885948651997);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1027278458891, 0.2059880507902);
    glVertex2f(1.097899618681, 0.2062562856351);
    glVertex2f(1.0997772625953, 0.084477666054);
    glVertex2f(1.1059466640278, 0.084477666054);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1343795575864, 0.141611688016);
    glVertex2f(1.0689302554327, 0.141611688016);
    glVertex2f(1.0681826603238, 0.1373026182134);
    glVertex2f(1.1346477924313, 0.136783460808);

    glEnd();
    glPopMatrix();


    //door
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1492149316986, -0.1375369036204);
    glVertex2f(1.0522232313853, -0.1374843759905);
    glVertex2f(1.0555625714527, -0.3139923509808);
    glVertex2f(1.1519284988326, -0.3121097225721);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.4, 0.55);
    glVertex2f(1.136660830232, -0.1665843394349);
    glVertex2f(1.0679658345601, -0.167538436597);
    glVertex2f(1.0693483085018, -0.3242565715984);
    glVertex2f(1.1382449043843, -0.3236386649088);

    glEnd();


    // 1st building
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.78f, 0.2f);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.1003671436968f, -0.2916575248458f);
    glVertex2f(-0.78f, -0.29f);

    glEnd();

    // 1st building building block 1
    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.18f, 0.18f);
    glVertex2f(-0.78f, 0.1502218989579f);
    glVertex2f(-0.1f, 0.15f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.78f, 0.099958670257f);

    glEnd();

    // 1st building building block 2
    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.18f, 0.18f);
    glVertex2f(-0.78f, 0.0497783022499f);
    glVertex2f(-0.1001120119616f, 0.0500000836446f);
    glVertex2f(-0.1001493492822f, 0.0f);
    glVertex2f(-0.78f, 0.0f);

    glEnd();

    // 1st building building block 3
    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.18f, 0.18f);
    glVertex2f(-0.78f, -0.0495230296536f);
    glVertex2f(-0.1f, -0.05f);
    glVertex2f(-0.1002240239233f, -0.0999998327108f);
    glVertex2f(-0.78f, -0.1001619491857f);

    glEnd();

    // 1st building building block 4
    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.18f, 0.18f);
    glVertex2f(-0.78f, -0.1502994932769f);
    glVertex2f(-0.1002613612438f, -0.1499998048293f);
    glVertex2f(-0.1002986987309f, -0.2f);
    glVertex2f(-0.78f, -0.1999356619272f);

    glEnd();



    // 1st building line strip 1
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.765f, 0.2f);
    glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.7650000892196f, -0.2900365825822f);
    glVertex2f(-0.7600001189594f, -0.2900487767762f);

    glEnd();

    // 1st building line strip 2
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.705f, 0.2f);
    glVertex2f(-0.7f, 0.2f);
    glVertex2f(-0.7050392374281f, -0.2901828183044f);
    glVertex2f(-0.6999914142481f, -0.2901951292047f);

    glEnd();


    // 1st building line strip 3
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.64f, 0.2f);
    glVertex2f(-0.645f, -0.29f);
    glVertex2f(-0.64f, -0.29f);

    glEnd();


    // 1st building line strip 4
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.585f, 0.2f);
    glVertex2f(-0.58f, 0.2f);
    glVertex2f(-0.585f, -0.29f);
    glVertex2f(-0.58f, -0.29f);

    glEnd();


    // 1st building line strip 5
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.525f, 0.2f);
    glVertex2f(-0.52f, 0.2f);
    glVertex2f(-0.525f, -0.29f);
    glVertex2f(-0.52f, -0.29f);

    glEnd();


    // 1st building line strip 6
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.465f, 0.2f);
    glVertex2f(-0.46f, 0.2f);
    glVertex2f(-0.465f, -0.29f);
    glVertex2f(-0.46f, -0.29f);

    glEnd();


    // 1st building line strip 7
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.405f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.405f, -0.29f);
    glVertex2f(-0.4f, -0.29f);

    glEnd();


    // 1st building line strip 8
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.345f, 0.2f);
    glVertex2f(-0.34f, 0.2f);
    glVertex2f(-0.345f, -0.29f);
    glVertex2f(-0.34f, -0.29f);

    glEnd();


    // 1st building line strip 9
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.285f, 0.2f);
    glVertex2f(-0.28f, 0.2f);
    glVertex2f(-0.285f, -0.29f);
    glVertex2f(-0.28f, -0.29f);

    glEnd();


    // 1st building line strip 10
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.225f, 0.2f);
    glVertex2f(-0.22f, 0.2f);
    glVertex2f(-0.225f, -0.29f);
    glVertex2f(-0.22f, -0.29f);

    glEnd();


    // 1st building line strip 11
    glBegin(GL_QUADS);
    glColor3f(0.51f, 0.51f, 0.51f);
    glVertex2f(-0.165f, 0.2f);
    glVertex2f(-0.16f, 0.2f);
    glVertex2f(-0.165f, -0.29f);
    glVertex2f(-0.16f, -0.29f);

    glEnd();


    //2nd building
    glBegin(GL_QUADS);
    glColor3f(0.11f, 0.25f, 0.25f);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(-0.1002986987309f, -0.2f);

    glEnd();

    //2nd building middle part
    glBegin(GL_QUADS);
    glColor3f(0.18f, 0.41f, 0.41f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.1f,0.5f);
    glVertex2f(0.1f, -0.2f);
    glVertex2f(0.0f, -0.2f);

    glEnd();

    //2nd building top part
    glBegin(GL_QUADS);
    glColor3f(0.52f, 0.53f, 0.53f);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.2f, 0.4606340559496f);
    glVertex2f(-0.1f, 0.4627838753471f);

    glEnd();


    //2nd building bottom part
    glBegin(GL_QUADS);
    glColor3f(0.52f, 0.53f, 0.53f);
    glVertex2f(-0.1002240239233f, -0.0999998327108f);
    glVertex2f(0.2f,-0.1f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(-0.1002986987309f, -0.2f);

    glEnd();


    //2nd building top antina
    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.27f, 0.27f);
    glVertex2f(-0.09f, 0.64f);
    glVertex2f(-0.08f, 0.64f);
    glVertex2f(-0.08f, 0.5f);
    glVertex2f(-0.09f, 0.5f);

    glEnd();


    //3rd building
    glBegin(GL_QUADS);
    glColor3f(0.25f, 0.25f, 0.53f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.6f, 0.1f);
    glVertex2f(0.6f, -0.2f);
    glVertex2f(0.2f, -0.2f);

    glEnd();

    //4th building
    glBegin(GL_QUADS);
    glColor3f(0.33f, 0.21f, 0.3f);
    glVertex2f(0.64f, 0.0f);
    glVertex2f(0.98f, 0.0f);
    glVertex2f(0.98f, -0.2f);
    glVertex2f(0.64f, -0.2f);

    glEnd();

    //5th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.62f);
    glVertex2f(0.24f, 0.18f);
    glVertex2f(0.32f, 0.18f);
    glVertex2f(0.32f, 0.1f);
    glVertex2f(0.24f, 0.1f);

    glEnd();

    //6th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.62f);
    glVertex2f(0.34f, 0.24f);
    glVertex2f(0.42f, 0.24f);
    glVertex2f(0.42f, 0.1f);
    glVertex2f(0.34f, 0.1f);

    glEnd();

    //7th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.62f);
    glVertex2f(0.44f, 0.2f);
    glVertex2f(0.52f, 0.2f);
    glVertex2f(0.52f, 0.1f);
    glVertex2f(0.44f, 0.1f);

    glEnd();

    //8th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.62f);
    glVertex2f(0.54f, 0.28f);
    glVertex2f(0.58f, 0.28f);
    glVertex2f(0.58f, 0.1f);
    glVertex2f(0.54f, 0.1f);

    glEnd();

    //9th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.62f);
    glVertex2f(0.7f, 0.05f);
    glVertex2f(0.8f, 0.2f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.7f, 0.0f);

    glEnd();


    //10th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.62f);
    glVertex2f(0.85f, 0.3f);
    glVertex2f(0.95f, 0.2f);
    glVertex2f(0.95f, 0.0f);
    glVertex2f(0.85f, 0.0f);

    glEnd();




//airport circle 1

    int e;

    GLfloat x5=-1.1326898425755f;
    GLfloat y5= -0.2935784992873f;
    GLfloat radius5 =0.461f;
    int triangleAmount5 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi5 = 2.0f * PI;

    glColor3f(0.02f, 0.1f, 0.32f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(e = 0; e <= triangleAmount5; e++)
    {
        glVertex2f( x5 + (radius5 * cos(e *  twicePi5 / triangleAmount5)),
                    y5 + (radius5 * sin(e * twicePi5 / triangleAmount5)) );
    }
    glEnd();

//airport circle 2

    int d;

    GLfloat x6=-1.1536890443764;
    GLfloat y6=-0.3119528008631f;
    GLfloat radius6 =0.4621f;
    int triangleAmount6 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi6 = 2.0f * PI;

    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(d = 0; d <= triangleAmount6; d++)
    {
        glVertex2f( x6 + (radius6 * cos(d *  twicePi6 / triangleAmount6)),
                    y6 + (radius6 * sin(d * twicePi6 / triangleAmount6)) );
    }
    glEnd();


    // Airport window bar v1
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-0.9606162289803f, 0.1078561833019f);
    glVertex2f(-0.95f, 0.1f);
    glVertex2f(-0.95f, -0.3f);
    glVertex2f(-0.9599746940333f, -0.3f);

    glEnd();

    // Airport window bar v2
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-0.9097650027526f, 0.0804981605939f);
    glVertex2f(-0.9002293018899f, 0.0744082403526f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.91f, -0.3f);

    glEnd();

    // Airport window bar v3
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-0.8601043860089f, 0.0448731281301f);
    glVertex2f(-0.8500743783898f, 0.0363786933037f);
    glVertex2f(-0.85f, -0.3f);
    glVertex2f(-0.86f, -0.3f);

    glEnd();

    // Airport window bar v4
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-0.8100323302338f, -0.0030567697211f);
    glVertex2f(-0.7999410061433f, -0.01466670856f);
    glVertex2f(-0.8f, -0.29f);
    glVertex2f(-0.81f, -0.29f);

    glEnd();

    // Airport window bar h1
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-1.0f, -0.0402407102493f);
    glVertex2f(-0.78f,-0.0401565658935f);
    glVertex2f(-0.7731411859559f, -0.0498459091525f);
    glVertex2f(-1.0f, -0.05f);

    glEnd();

    // Airport window bar h2
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-1.0f, -0.140510115229f);
    glVertex2f(-0.7247969177398f, -0.1399986240026f);
    glVertex2f(-0.72088190096966f, -0.1502734011025f);//
    glVertex2f(-1.0f, -0.15f);

    glEnd();


    // ramp
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.2f, -0.3f);

    glEnd();

    // ramp block
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(-0.2, -0.2);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-0.2f, -0.3f);

    glEnd();


    //ramp piller 1 top
    glBegin(GL_POLYGON);
    glColor3f(0.68f, 0.68f, 0.68f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.46f, -0.2f);
    glVertex2f(0.46f, -0.22f);
    glVertex2f(0.4f, -0.22f);

    glEnd();

    //ramp piller 1 stand
    glBegin(GL_POLYGON);
    glColor3f(0.53f, 0.53f, 0.53f);
    glVertex2f(0.42f, -0.22f);
    glVertex2f(0.44f, -0.22f);
    glVertex2f(0.44f, -0.3f);
    glVertex2f(0.42f, -0.3f);

    glEnd();

    //ramp piller 2 top
    glBegin(GL_POLYGON);
    glColor3f(0.68f, 0.68f, 0.68f);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.76f, -0.2f);
    glVertex2f(0.76f, -0.22f);
    glVertex2f(0.7f, -0.22f);

    glEnd();

    //ramp piller 2 stand
    glBegin(GL_POLYGON);
    glColor3f(0.53f, 0.53f, 0.53f);
    glVertex2f(0.72f, -0.22f);
    glVertex2f(0.74f, -0.22f);
    glVertex2f(0.74f, -0.3f);
    glVertex2f(0.72f, -0.3f);

    glEnd();


    glPopMatrix();

}

void runway()
{
    glPushMatrix();
    glTranslatef(runway1,0.0f, 0.0f);

    // road lines 1
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-0.78f, -0.5f);
    glVertex2f(-0.9f, -1.0f);
    glVertex2f(-0.92f, -1.0f);

    glEnd();

    // road lines 2
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(-0.52f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.56f, -1.0f);
    glVertex2f(-0.58f, -1.0f);

    glEnd();

    // road lines 3
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(-0.22f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(-0.22f, -1.0f);

    glEnd();

    // road lines 4
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.12f, -0.5f);
    glVertex2f(0.12f, -1.0f);
    glVertex2f(0.1f, -1.0f);

    glEnd();

    // road lines 5
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(0.38f, -0.5f);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.46f, -1.0f);
    glVertex2f(0.44f, -1.0f);

    glEnd();

    // road lines 6
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(0.68f, -0.5f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.82f, -1.0f);
    glVertex2f(0.8f, -1.0f);

    glEnd();


    // road light 1
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.7, -0.68);
    glVertex2f(-0.66, -0.68);
    glVertex2f(-0.66, -0.7);
    glVertex2f(-0.7, -0.7);

    glEnd();

    // road light 2
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.72, -0.82);
    glVertex2f(-0.68, -0.82);
    glVertex2f(-0.68, -0.84);
    glVertex2f(-0.72, -0.84);

    glEnd();

    // road light 3
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.42, -0.68);
    glVertex2f(-0.38, -0.68);
    glVertex2f(-0.38, -0.7);
    glVertex2f(-0.42, -0.7);

    glEnd();

    // road light 4
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.43, -0.82);
    glVertex2f(-0.39, -0.82);
    glVertex2f(-0.39, -0.84);
    glVertex2f(-0.43, -0.84);

    glEnd();

    // road light 5
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.08, -0.68);
    glVertex2f(-0.04, -0.68);
    glVertex2f(-0.04, -0.7);
    glVertex2f(-0.08, -0.7);

    glEnd();

    // road light 6
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.08, -0.82);
    glVertex2f(-0.04, -0.82);
    glVertex2f(-0.04, -0.84);
    glVertex2f(-0.08, -0.84);

    glEnd();

    // road light 7
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.26, -0.68);
    glVertex2f(0.3, -0.68);
    glVertex2f(0.3, -0.7);
    glVertex2f(0.26, -0.7);

    glEnd();

    // road light 8
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.275, -0.8);
    glVertex2f(0.315, -0.8);
    glVertex2f(0.315, -0.82);
    glVertex2f(0.275, -0.82);

    glEnd();

    // road light 9
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.54, -0.68);
    glVertex2f(0.58, -0.68);
    glVertex2f(0.58, -0.7);
    glVertex2f(0.54, -0.7);

    glEnd();

    // road light 10
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.58, -0.8);
    glVertex2f(0.62, -0.8);
    glVertex2f(0.62, -0.82);
    glVertex2f(0.58, -0.82);

    glEnd();

    // road light 11
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.86, -0.68);
    glVertex2f(0.9, -0.68);
    glVertex2f(0.9, -0.7);
    glVertex2f(0.86, -0.7);

    glEnd();

    // road light 12
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.88, -0.8);
    glVertex2f(0.92, -0.8);
    glVertex2f(0.92, -0.82);
    glVertex2f(0.88, -0.82);

    glEnd();

    glPopMatrix();
}

void runway2()
{
    glPushMatrix();
    glTranslatef(runway22,0.0f, 0.0f);

    glTranslatef(2.3f,0.0f, 0.0f);
    //glScalef(-1.0f, 1.0f, 0.0f);

    // road lines 1
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-0.78f, -0.5f);
    glVertex2f(-0.9f, -1.0f);
    glVertex2f(-0.92f, -1.0f);

    glEnd();

    // road lines 2
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(-0.52f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.56f, -1.0f);
    glVertex2f(-0.58f, -1.0f);

    glEnd();

    // road lines 3
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(-0.22f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(-0.22f, -1.0f);

    glEnd();

    // road lines 4
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.12f, -0.5f);
    glVertex2f(0.12f, -1.0f);
    glVertex2f(0.1f, -1.0f);

    glEnd();

    // road lines 5
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(0.38f, -0.5f);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.46f, -1.0f);
    glVertex2f(0.44f, -1.0f);

    glEnd();

    // road lines 6
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.62f);
    glVertex2f(0.68f, -0.5f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.82f, -1.0f);
    glVertex2f(0.8f, -1.0f);

    glEnd();


    // road light 1
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.7, -0.68);
    glVertex2f(-0.66, -0.68);
    glVertex2f(-0.66, -0.7);
    glVertex2f(-0.7, -0.7);

    glEnd();

    // road light 2
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.72, -0.82);
    glVertex2f(-0.68, -0.82);
    glVertex2f(-0.68, -0.84);
    glVertex2f(-0.72, -0.84);

    glEnd();

    // road light 3
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.42, -0.68);
    glVertex2f(-0.38, -0.68);
    glVertex2f(-0.38, -0.7);
    glVertex2f(-0.42, -0.7);

    glEnd();

    // road light 4
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.43, -0.82);
    glVertex2f(-0.39, -0.82);
    glVertex2f(-0.39, -0.84);
    glVertex2f(-0.43, -0.84);

    glEnd();

    // road light 5
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.08, -0.68);
    glVertex2f(-0.04, -0.68);
    glVertex2f(-0.04, -0.7);
    glVertex2f(-0.08, -0.7);

    glEnd();

    // road light 6
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(-0.08, -0.82);
    glVertex2f(-0.04, -0.82);
    glVertex2f(-0.04, -0.84);
    glVertex2f(-0.08, -0.84);

    glEnd();

    // road light 7
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.26, -0.68);
    glVertex2f(0.3, -0.68);
    glVertex2f(0.3, -0.7);
    glVertex2f(0.26, -0.7);

    glEnd();

    // road light 8
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.275, -0.8);
    glVertex2f(0.315, -0.8);
    glVertex2f(0.315, -0.82);
    glVertex2f(0.275, -0.82);

    glEnd();

    // road light 9
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.54, -0.68);
    glVertex2f(0.58, -0.68);
    glVertex2f(0.58, -0.7);
    glVertex2f(0.54, -0.7);

    glEnd();

    // road light 10
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.58, -0.8);
    glVertex2f(0.62, -0.8);
    glVertex2f(0.62, -0.82);
    glVertex2f(0.58, -0.82);

    glEnd();

    // road light 11
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.86, -0.68);
    glVertex2f(0.9, -0.68);
    glVertex2f(0.9, -0.7);
    glVertex2f(0.86, -0.7);

    glEnd();

    // road light 12
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.0f, 0.0f);
    glVertex2f(0.88, -0.8);
    glVertex2f(0.92, -0.8);
    glVertex2f(0.92, -0.82);
    glVertex2f(0.88, -0.82);

    glEnd();

    glPopMatrix();
}


void plane()
{

    glPushMatrix();
    glTranslatef(s3BigP1,s3BigP1Y, 0.0f);

    glScalef(0.8,1.5,0);
    glRotatef(rotation,0.0,0.0,1.0);// i=how many degree you want to rotate around an axis
    // plane front wheel handle 1
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.5245190570464f, 0.099469824529f);
    glVertex2f(0.6156019104277f, 0.0962609435155f);
    glVertex2f(0.6153580810611f, 0.116320088294f);
    glVertex2f(0.5235134188893f, 0.1205472484777f);
    glVertex2f(0.5151392510071f, 0.0876216484794f);
    glVertex2f(0.4874935068914f, 0.0871279744773f);
    glVertex2f(0.4872466698904f, 0.0644189703823f);
    glVertex2f(0.4926770839131f, 0.0641721333812f);
    glVertex2f(0.4929239209142f, 0.0814507234536f);
    glVertex2f(0.52f, 0.08f);

    glEnd();

    //glPushMatrix();
    //glRotatef(i,0.0,0.0,1.0);
    //front wheel 1
    int h;

    GLfloat x0=0.4940803976506f;
    GLfloat y0=0.0483447077868f;
    GLfloat radius0 =0.02f;
    int triangleAmount0 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi0 = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x0, y0); // center of circle
    for(h = 0; h <= triangleAmount0; h++)
    {
        glVertex2f( x0 + (radius0 * cos(h *  twicePi0 / triangleAmount0)),
                    y0 + (radius0 * sin(h * twicePi0 / triangleAmount0)) );
    }
    glEnd();

    //front wheel inner 1

    int g;

    GLfloat x4=0.4940803976506f;
    GLfloat y4=0.0483447077868f;
    GLfloat radius4 =0.01f;
    int triangleAmount4 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi4 = 2.0f * PI;

    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(g = 0; g <= triangleAmount4; g++)
    {
        glVertex2f( x4 + (radius4 * cos(g *  twicePi4 / triangleAmount4)),
                    y4 + (radius4 * sin(g * twicePi4 / triangleAmount4)) );
    }
    glEnd();
    //i+=0.2f;
    //glPopMatrix();

    // plane back wheel handle 1
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.9f);
    glVertex2f(-0.0681899902642f, 0.1519549983379f);
    glVertex2f(-0.0524334107819f, 0.1492692177443f);
    glVertex2f(-0.0467037455156f, 0.1127426016718f);
    glVertex2f(-0.0578049719691f, 0.1025366354162f);

    glEnd();

    // plane back wheel handle 2
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.9f);
    glVertex2f(-0.0567076282201f, 0.0906151074325f);
    glVertex2f(-0.0490448663273f, 0.0825692074451f);
    glVertex2f(-0.062071561545f, 0.0714582027006f);
    glVertex2f(-0.0678186329646f, 0.0808450860192f);

    glEnd();

    //back wheel 1
    int i;

    GLfloat x=-0.039274844914f;
    GLfloat y=0.0963621788521f;
    GLfloat radius =0.02f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //back wheel inner 1

    int j;

    GLfloat x1=-0.039274844914f;
    GLfloat y1=0.0963621788521f;
    GLfloat radius1 =0.01f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(j = 0; j <= triangleAmount; j++)
    {
        glVertex2f( x1 + (radius1 * cos(j *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(j * twicePi / triangleAmount)) );
    }
    glEnd();

    //back wheel 2
    int k;

    GLfloat x2=-0.0783549305672f;
    GLfloat y2=0.0666689765176f;
    GLfloat radius2 =0.02f;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(k = 0; k <= triangleAmount2; k++)
    {
        glVertex2f( x2 + (radius2 * cos(k *  twicePi2 / triangleAmount2)),
                    y2 + (radius2 * sin(k * twicePi2 / triangleAmount2)) );
    }
    glEnd();

    //back wheel inner 2

    int l;

    GLfloat x3=-0.0783549305672f;
    GLfloat y3=0.0666689765176f;
    GLfloat radius3 =0.01f;
    int triangleAmount3 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi3 = 2.0f * PI;

    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(l = 0; l <= triangleAmount3; l++)
    {
        glVertex2f( x3 + (radius3 * cos(l *  twicePi3 / triangleAmount3)),
                    y3 + (radius3 * sin(l * twicePi3 / triangleAmount3)) );
    }
    glEnd();

    // plane back wing black
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.8090204799838f, 0.5755043164711f);
    glVertex2f(-0.7456890174596f, 0.5674194489148f);
    glVertex2f(-0.6055513131507f, 0.4259342666799f);
    glVertex2f(-0.5745593208516f, 0.4030271419371f);
    glVertex2f(-0.4869339446724f, 0.3617065720574f);
    glVertex2f(-0.7336440825104f, 0.3616009351106f);

    glEnd();

    // plane body
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.8f);
    glVertex2f(0.5236351888768f, 0.2736692610366f);
    glVertex2f(0.6220010774782f, 0.1160143436891f);
    glVertex2f(0.2999538531529f, 0.1308366008756f);
    glVertex2f(0.2514446478152f, 0.1079294761328f);
    glVertex2f(-0.3818699774269f, 0.1631760711007f);
    glVertex2f(-0.4290317048386f, 0.1914731075477f);
    glVertex2f(-0.5637794974433f, 0.2116852764384f);
    glVertex2f(-0.8319276047266f, 0.3262209001524f);
    glVertex2f(-0.8238427371704f, 0.3572128924515f);
    glVertex2f(-0.7336440825104f, 0.3616009351106f);
    glVertex2f(-0.5745593208516f, 0.3693401937859f);
    glVertex2f(-0.5745593208516f, 0.3693401937859f);

    glEnd();

    // plane head
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.8f);
    glVertex2f(0.5236351888768f, 0.2736692610366f);
    glVertex2f(0.5706609137126f, 0.2590951391016f);
    glVertex2f(0.6327815279829f, 0.2288245007919f);
    glVertex2f(0.6975343716714f, 0.1767063583109f);
    glVertex2f(0.7043781681588f, 0.1703890077072f);
    glVertex2f(0.7080632893443f, 0.1635452112198f);
    glVertex2f(0.708589735228f, 0.1585439753251f);
    glVertex2f(0.7075368434607f, 0.1524898476632f);
    glVertex2f(0.7070103975771f, 0.1474886117685f);
    glVertex2f(0.7049046140425f, 0.1403815923393f);
    glVertex2f(0.7020091616824f, 0.134853910561f);
    glVertex2f(0.6975343716714f, 0.13037912055f);
    glVertex2f(0.6917434669513f, 0.1269572223063f);
    glVertex2f(0.6838467786966f, 0.1251146617135f);
    glVertex2f(0.6643682810017f, 0.1198502028771f);
    glVertex2f(0.641467885063f, 0.1166915275752f);
    glVertex2f(0.6153580810611f, 0.116320088294f);

    glEnd();

    // plane head windows
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6241364630655f, 0.2282065313095f);
    glVertex2f(0.6325980888564f, 0.2273411377627f);
    glVertex2f(0.6628868629945f, 0.2026293442596f);
    glVertex2f(0.6379827598143f, 0.2038793571605f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6060593534211f, 0.2282065313095f);
    glVertex2f(0.61990565017f, 0.2282065313095f);
    glVertex2f(0.6326942436949f, 0.2047447507073f);
    glVertex2f(0.6122132630873f, 0.2055139894156f);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6006746824633f, 0.2289757700178f);
    glVertex2f(0.5822129534648f, 0.2300334732416f);
    glVertex2f(0.5812514050795f, 0.2272449829242f);
    glVertex2f(0.5816360244336f, 0.2248411119608f);
    glVertex2f(0.5825975728189f, 0.2216680022892f);
    glVertex2f(0.5839437405584f, 0.2189756668103f);
    glVertex2f(0.5857706824905f, 0.2158987119772f);
    glVertex2f(0.5924053663494f, 0.2110909700505f);
    glVertex2f(0.5954823211824f, 0.2089755636028f);
    glVertex2f(0.598463121177f, 0.2078217055404f);
    glVertex2f(0.6017323856871f, 0.2071486216706f);
    glVertex2f(0.6046170308431f, 0.206860157155f);
    glVertex2f(0.6073093663221f, 0.2067640023165f);

    glEnd();

    // plane main wing
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.3622896100725f, 0.3551724823639f);
    glVertex2f(-0.3953672810171f, 0.3781243356724f);
    glVertex2f(-0.4203442978528f, 0.4085017885806f);
    glVertex2f(-0.4648978954516f, 0.4145772791623f);
    glVertex2f(-0.4358653242707f, 0.3572576492985f);
    glVertex2f(-0.4196692433437f, 0.3362709561099f);
    glVertex2f(-0.0396135547359f, 0.1627819472782f);
    glVertex2f(0.2378338484929f, 0.1810084190232f);

    glEnd();

    // plane back engine
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.8f);
    glVertex2f(0.1800998239982f, 0.1910319311585f);
    glVertex2f(0.1314973631666f, 0.1999624061909f);
    glVertex2f(0.0657838771167f, 0.2025143862317f);
    glVertex2f(0.0233572089389f, 0.200281403696f);
    glVertex2f(0.0255901914745f, 0.1147900723301f);
    glVertex2f(0.08f, 0.1f);
    glVertex2f(0.1133145053761f, 0.0962882170345f);
    glVertex2f(0.1480852334316f, 0.0956502220243f);
    glVertex2f(0.1752667746638f, 0.0958418725289f);

    glEnd();

    // plane back engine front
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.1890851624739f, 0.1116490411534f);
    glVertex2f(0.1894731598771f, 0.1310489113146f);
    glVertex2f(0.1894731598771f, 0.145792812637f);
    glVertex2f(0.19102514949f, 0.163252695782f);
    glVertex2f(0.194517126119f, 0.1869205373786f);
    glVertex2f(0.1800998239982f, 0.1910319311585f);
    glVertex2f(0.1766692455708f, 0.1791605893141f);
    glVertex2f(0.1751172559579f, 0.1531647632982f);
    glVertex2f(0.1739532637482f, 0.1329888983307f);
    glVertex2f(0.173565266345f, 0.117856999605f);
    glVertex2f(0.1743412611515f, 0.1062170775083f);
    glVertex2f(0.1914131468932f, 0.096905139831f);

    glEnd();

    // plane front engine back black
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.1161956386842f, 0.2033128222786f);
    glVertex2f(-0.1117143521201f, 0.1976453128004f);
    glVertex2f(-0.1040446787375f, 0.1966186418419f);
    glVertex2f(-0.103610908584f, 0.2086090542575f);

    glEnd();

    // plane front engine back white
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.0758271039242f, 0.2233020392264f);
    glVertex2f(-0.0980103772117f, 0.2230415504432f);
    glVertex2f(-0.1035011878185f, 0.2121727970232f);
    glVertex2f(-0.1044121930099f, 0.188486662047f);
    glVertex2f(-0.1024535087865f, 0.1766663646318f);
    glVertex2f(-0.0781032001338f, 0.1732283301649f);

    glEnd();

    // plane front engine
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.8f);
    glVertex2f(0.0608517127137f, 0.2284586868956f);
    glVertex2f(-0.0008168740142f, 0.2374817280611f);
    glVertex2f(-0.0749616321677f, 0.2330385964864f);
    glVertex2f(-0.0782939808488f, 0.1955496738244f);
    glVertex2f(-0.0780162851254f, 0.1630592741841f);
    glVertex2f(-0.0188670960366f, 0.1500075751833f);
    glVertex2f(0.0564398427306f, 0.1435950701622f);

    glEnd();

    // plane front engine front
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.0727897138444f, 0.1386641566517f);
    glVertex2f(0.0717516267896f, 0.156311636584f);
    glVertex2f(0.0720111485533f, 0.1744781600438f);
    glVertex2f(0.0727897138444f, 0.187713769993f);
    glVertex2f(0.0730492356081f, 0.1999112928875f);
    glVertex2f(0.0730492356081f, 0.2152230769464f);
    glVertex2f(0.074087322663f, 0.2243063386763f);
    glVertex2f(0.0608517127137f, 0.2284586868956f);
    glVertex2f(0.0574779297855f, 0.2191159034021f);
    glVertex2f(0.0561803209669f, 0.2063993369802f);
    glVertex2f(0.0554017556758f, 0.189530422339f);
    glVertex2f(0.0554017556758f, 0.1736995947527f);
    glVertex2f(0.0561803209669f, 0.15812828893f);
    glVertex2f(0.0564398427306f, 0.1435950701622f);
    glVertex2f(0.0574278399895f, 0.1248543466027f);
    glVertex2f(0.0751254097178f, 0.1254285467025f);

    glEnd();

    // plane back wing white
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.9570295201674f, 0.4040138687843f);
    glVertex2f(-0.8915633555276f, 0.4019465162167f);
    glVertex2f(-0.5793931178241f, 0.3233871186489f);
    glVertex2f(-0.7247969150767f, 0.3316565289192f);

    glEnd();

    // plane door
    glBegin(GL_POLYGON);
    glColor3f(0.86f, 0.86f, 0.86f);
    glVertex2f(-0.4952071172999f, 0.300477330771f);
    glVertex2f(-0.48923080062f, 0.3412721881081f);
    glVertex2f(-0.5261280601223f, 0.3443902663759f);
    glVertex2f(-0.5336634159361f, 0.3103512452857f);
    glVertex2f(-0.5388602130491f, 0.263320231413f);
    glVertex2f(-0.5f, 0.26f);

    glEnd();

    //door lining black
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.4952071172999f, 0.300477330771f);
    glVertex2f(-0.48923080062f, 0.3412721881081f);
    glVertex2f(-0.5261280601223f, 0.3443902663759f);
    glVertex2f(-0.5336634159361f, 0.3103512452857f);
    glVertex2f(-0.5388602130491f, 0.263320231413f);
    glVertex2f(-0.5f, 0.26f);

    glEnd();

    // plane door handle
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.5280969155672f, 0.309743167321f);
    glVertex2f(-0.5236446209512f, 0.3093721427697f);
    glVertex2f(-0.5234962111306f, 0.3032873401278f);
    glVertex2f(-0.5283937352083f, 0.3035841597688f);

    glEnd();

    // windows from left
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.4317507015787f, 0.3059640036878f);
    glVertex2f(-0.41980263077f, 0.3058512860386f);
    glVertex2f(-0.4201407837174f, 0.2884927680712f);
    glVertex2f(-0.4322015721753f, 0.2888309210186f);
    glVertex2f(-0.4083103967184f, 0.304733234731f);
    glVertex2f(-0.3954994229691f, 0.3045601134641f);
    glVertex2f(-0.3958456655029f, 0.2869017442421f);
    glVertex2f(-0.4084835179853f, 0.2872479867759f);
    glVertex2f(-0.3854583894899f, 0.3021364157278f);
    glVertex2f(-0.3728205370075f, 0.301790173194f);
    glVertex2f(-0.3735130220751f, 0.2846511677727f);
    glVertex2f(-0.3863239958243f, 0.2848242890396f);
    glVertex2f(-0.3629526247952f, 0.3005783243258f);
    glVertex2f(-0.35f, 0.3f);
    glVertex2f(-0.3511803786473f, 0.2825737125701f);
    glVertex2f(-0.3639913523965f, 0.2832661976376f);
    glVertex2f(-0.339754375033f, 0.2962502926538f);
    glVertex2f(-0.330490590684f, 0.2955624059615f);
    glVertex2f(-0.3302327053545107f, 0.2815349849687969f);
    glVertex2f(-0.3399274962999f, 0.2815349849688f);
    glVertex2f(-0.0023704839348f, 0.2713523698652f);
    glVertex2f(0.0126727368111f, 0.2697688729446f);
    glVertex2f(0.0126727368111f, 0.2505689727821f);
    glVertex2f(-0.0019746097046f, 0.2525483439329f);
    glVertex2f(0.0223716554498f, 0.2701647471747f);
    glVertex2f(0.0368210648505f, 0.268383313139f);
    glVertex2f(0.0364251906203f, 0.2483916645163f);
    glVertex2f(0.0221737183348f, 0.2507669098972f);
    glVertex2f(0.0483918318285f, 0.2683231111313f);
    glVertex2f(0.0651481138587f, 0.2666474829283f);
    glVertex2f(0.0651481138587f, 0.2463005690344f);
    glVertex2f(0.0495887091163f, 0.2477368217799f);
    glVertex2f(0.0766381358223f, 0.265689981098f);
    glVertex2f(0.0910006632769f, 0.2642537283525f);
    glVertex2f(0.0912400387344f, 0.2446249408314f);
    glVertex2f(0.0771168867375f, 0.2458218181193f);
    glVertex2f(0.1017559937361f, 0.2633079581596f);
    glVertex2f(0.1160084556224f, 0.2620316182892f);
    glVertex2f(0.1153702856872f, 0.242886520233f);
    glVertex2f(0.1013305471127f, 0.24373741348f);
    glVertex2f(0.1264318978974f, 0.2616061716657);
    glVertex2f(0.14f, 0.26f);
    glVertex2f(0.14f, 0.24f);
    glVertex2f(0.1268858928591f, 0.2418022452715f);
    glVertex2f(0.1521714186172f, 0.2603298317953f);
    glVertex2f(0.1655729872565f, 0.2590534919249f);
    glVertex2f(0.1657857105683f, 0.2375684374397f);
    glVertex2f(0.1526405630745f, 0.2391682449085f);
    glVertex2f(0.1757837062198f, 0.2579898753662f);
    glVertex2f(0.1891852748591f, 0.2571389821193f);
    glVertex2f(0.1898234447943f, 0.2354412043223f);
    glVertex2f(0.1760538996339f, 0.2368269112526f);
    glVertex2f(0.1987578238871f, 0.2565008121841f);
    glVertex2f(0.2134357323968f, 0.2550117490019f);
    glVertex2f(0.2134357323968f, 0.2331012478933f);
    glVertex2f(0.1985451005754f, 0.2352284810106f);
    glVertex2f(0.2252303092545f, 0.2543425048199f);
    glVertex2f(0.2398830608291f, 0.2528772296624f);
    glVertex2f(0.2405110358966f, 0.2306887772779f);
    glVertex2f(0.225439634277f, 0.2321540524354f);
    glVertex2f(0.2502516780386f, 0.2522293475f);
    glVertex2f(0.2657918808745f, 0.2505296378148f);
    glVertex2f(0.2655490652052f, 0.2291618589155f);
    glVertex2f(0.2497660467f, 0.230375937262f);
    glVertex2f(0.2764055146919f, 0.2508339324349f);
    glVertex2f(0.2919491298378f, 0.2494619418215f);
    glVertex2f(0.2922288349323f, 0.2286204251743f);
    glVertex2f(0.2764055146919f, 0.2298376036543f);
    glVertex2f(0.3040682472035f, 0.2487051826409f);
    glVertex2f(0.3197138283048f, 0.2476335674969f);
    glVertex2f(0.3197138283048f, 0.2272728797624f);
    glVertex2f(0.3040682472035f, 0.2285588179351f);
    glVertex2f(0.3306443027728f, 0.2467762753818f);
    glVertex2f(0.3469328529604f, 0.2448473681227f);
    glVertex2f(0.3460755608453f, 0.2240580343306f);
    glVertex2f(0.330429979744f, 0.2262012646185f);
    glVertex2f(0.3585062965148f, 0.2444187220652f);
    glVertex2f(0.3730802624721f, 0.2427041378349f);
    glVertex2f(0.3728659394433f, 0.2227720961579f);
    glVertex2f(0.3578633274284f, 0.2251296494746f);
    glVertex2f(0.3855109981416f, 0.2418468457198f);
    glVertex2f(0.4f, 0.24f);
    glVertex2f(0.4f, 0.22f);
    glVertex2f(0.3846537060264f, 0.2219148040428f);
    glVertex2f(0.4120870537108f, 0.2373460621153f);
    glVertex2f(0.4260180505818f, 0.2364887700001f);
    glVertex2f(0.4255894045243f, 0.2161280822656f);
    glVertex2f(0.4112297615957f, 0.2171996974095f);
    glVertex2f(0.4373771711074f, 0.2358458009138f);
    glVertex2f(0.4523797831223f, 0.2349885087987f);
    glVertex2f(0.4515224910072f, 0.2135562059202f);
    glVertex2f(0.4365198789923f, 0.2148421440929f);

    glEnd();

    // plane front door
    glBegin(GL_POLYGON);
    glColor3f(0.86f, 0.86f, 0.86f);
    glVertex2f(0.4941688680944f, 0.2584221776184f);
    glVertex2f(0.5318260515611f, 0.256941277145f);
    glVertex2f(0.5309798227191f, 0.1718952785293f);
    glVertex2f(0.4912070671476f, 0.1746455222656f);

    glEnd();

    //door lining black
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.4941688680944f, 0.2584221776184f);
    glVertex2f(0.5318260515611f, 0.256941277145f);
    glVertex2f(0.5309798227191f, 0.1718952785293f);
    glVertex2f(0.4912070671476f, 0.1746455222656f);

    glEnd();

    // plane door handle
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.5012664477161f, 0.2250812660463f);
    glVertex2f(0.507821425438f, 0.2250812660463f);
    glVertex2f(0.5073844269232f, 0.2167782942652f);
    glVertex2f(0.5013097320512f, 0.2171638975459f);

    glEnd();
    glPopMatrix();
    rotation=4.0f;

}

void plane2()
{
    //Plane
    //plane body
    glPushMatrix();
    glTranslatef(s3smallp2,0.6f, 0.0f);

    glScalef(-0.3,0.4,0);

    glBegin(GL_POLYGON);
    glColor3f(0.95f, 0.0f, 0.0f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.8375889660587f, 0.2912098678332f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.928861465027f, 0.2556290631507f);
    glVertex2f(-0.9041096009f, 0.2378386608094f);
    glVertex2f(-0.8731697707412f, 0.2277832160078f);
    glVertex2f(-0.8453239235984f, 0.2192747627141f);
    glVertex2f(-0.8143840934396f, 0.2107663094205f);
    glVertex2f(-0.7842177590348f, 0.2068988306506f);
    glVertex2f(-0.7439959798284f, 0.2076723264046f);
    glVertex2f(-0.3897349245107f, 0.2092193179125f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head
    glBegin(GL_POLYGON);
    glColor3f(0.95f, 0.0f, 0.0f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.4043823800643f, 0.2892785841354f);
    glVertex2f(-0.3831964687035f, 0.2802549552225f);
    glVertex2f(-0.3545562551972f, 0.2671118435449f);
    glVertex2f(-0.3380783241388f, 0.2622076973966f);
    glVertex2f(-0.3237582173856f, 0.2573035512482f);
    glVertex2f(-0.3176770761617f, 0.2518109075621f);
    glVertex2f(-0.3121844324755f, 0.2463182638759f);
    glVertex2f(-0.31f, 0.24f);
    glVertex2f(-0.3098304423243f, 0.2357253081955f);
    glVertex2f(-0.31f, 0.23f);
    glVertex2f(-0.313753759243f, 0.2259170158989f);
    glVertex2f(-0.3204233980047f, 0.2227783623639f);
    glVertex2f(-0.3280738659961f, 0.2190512112912f);
    glVertex2f(-0.3378821582928f, 0.2157163919103f);
    glVertex2f(-0.3500444407407f, 0.2127739042213f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head window
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.3819451920869f, 0.2758911800548f);
    glVertex2f(-0.3881479557192f, 0.2728587178345f);
    glVertex2f(-0.3771897399688f, 0.2608667081453f);
    glVertex2f(-0.370504539165f, 0.2634167331942f);
    glVertex2f(-0.3660936850265f, 0.2658289190512f);
    glVertex2f(-0.360855795737f, 0.2696194968265f);
    glVertex2f(-0.3786950838177f, 0.2781892511995f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.398899412682f, 0.2686546224837f);
    glVertex2f(-0.4098576284324f, 0.2679654265246f);
    glVertex2f(-0.40854815611f, 0.262727537235f);
    glVertex2f(-0.4031035080328f, 0.2555598992599f);
    glVertex2f(-0.3925588098578f, 0.2561801756231f);
    glVertex2f(-0.3804978805727f, 0.2588680398638f);
    glVertex2f(-0.39f, 0.27f);
    glVertex2f(-0.39f, 0.27f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4127657925046f, 0.2602777634305f);
    glVertex2f(-0.4148377327393f, 0.2667761214393f);
    glVertex2f(-0.4317899710231f, 0.2668703005408f);
    glVertex2f(-0.432260866531f, 0.260371942532f);
    glVertex2f(-0.4296238516869f, 0.2515191069838f);
    glVertex2f(-0.4077743001211f, 0.2526492562027f);

    glEnd();

    //front door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4695704482148f, 0.2425964533209f);
    glVertex2f(-0.4727942748017f, 0.2424499157487f);
    glVertex2f(-0.4726477372296f, 0.2379072510126f);
    glVertex2f(-0.4692773730705f, 0.2380537885847f);

    glEnd();

    //upper wing
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.7f, 0.2f);
    glVertex2f(-0.5498485455822f, 0.2873423890634f);
    glVertex2f(-0.6217836507013f, 0.3770678965238f);
    glVertex2f(-0.6565909596299f, 0.3778413922778f);
    glVertex2f(-0.6488595295804f, 0.2915606660423f);

    glEnd();

    //lower wing
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.7f, 0.2f);
    glVertex2f(-0.8512841908058f, 0.1241487992192f);
    glVertex2f(-0.8652666039946f, 0.1246309513981f);
    glVertex2f(-0.8522484951637f, 0.1101663860304f);
    glVertex2f(-0.8291051905754f, 0.1111306903883f);
    glVertex2f(-0.5055818995018f, 0.2087134359257f);
    glVertex2f(-0.7114611649165f, 0.2078143998322f);

    glEnd();

    //lower wing back
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.7f, 0.2f);
    glVertex2f(-0.847900370437f, 0.2811701757442f);
    glVertex2f(-0.9292604039938f, 0.2448081495735f);
    glVertex2f(-0.9792581899784f, 0.2452626749007f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);

    glEnd();

    //upper wing back
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.7f, 0.2f);
    glVertex2f(-0.8228925467333f, 0.3035857998967f);
    glVertex2f(-0.8414564448285f, 0.3120942531904f);
    glVertex2f(-0.8561528641539f, 0.3283376640237f);
    glVertex2f(-0.9056565924079f, 0.3909908200952f);
    glVertex2f(-0.9427843885984f, 0.3894438285873f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.7617837686202f, 0.2913507696872f);
    glVertex2f(-0.7934997080824f, 0.2958508423571f);
    glVertex2f(-0.8097431189158f, 0.2989448253729f);

    glEnd();

    //back door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7678874563725f, 0.2510951983408f);
    glVertex2f(-0.7708790248524f, 0.2509192237244f);
    glVertex2f(-0.7707910375442f, 0.2473997313951f);
    glVertex2f(-0.7677114817561f, 0.2476636933198f);

    glEnd();

    //windows from left
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7151099662305f, 0.266868589599f);
    glVertex2f(-0.714460252525f, 0.2434788962022f);
    glVertex2f(-0.6962682687719f, 0.2434788962022f);
    glVertex2f(-0.6975676961829f, 0.266868589599f);

    glVertex2f(-0.6819745672516f, 0.26816801701f);
    glVertex2f(-0.6813248535462f, 0.2441286099077f);
    glVertex2f(-0.6637825834985f, 0.2444534667604f);
    glVertex2f(-0.6641074403513f, 0.2678431601572f);

    glVertex2f(-0.6501385956837f, 0.266868589599f);
    glVertex2f(-0.6491640251255f, 0.2447783236131f);
    glVertex2f(-0.6316217550779f, 0.2444534667604f);
    glVertex2f(-0.6329211824888f, 0.2671934464518f);

    glVertex2f(-0.6196020515268f, 0.2671934464518f);
    glVertex2f(-0.6183026241158f, 0.2451031804659f);
    glVertex2f(-0.6014100677737f, 0.2447783236131f);
    glVertex2f(-0.6030343520373f, 0.266868589599f);

    glVertex2f(-0.5858169388425f, 0.2662188758936f);
    glVertex2f(-0.585167225137f, 0.2457528941713f);
    glVertex2f(-0.5702238099112f, 0.2454280373186f);
    glVertex2f(-0.5711983804694f, 0.266868589599f);

    glVertex2f(-0.5533312535691f, 0.266868589599f);
    glVertex2f(-0.5520318261581f, 0.2454280373186f);
    glVertex2f(-0.5370884109324f, 0.2447783236131f);
    glVertex2f(-0.5393624089015f, 0.266868589599f);

    glVertex2f(-0.5227947094121f, 0.2665437327463f);
    glVertex2f(-0.5208455682957f, 0.2431540393495f);
    glVertex2f(-0.5039530119536f, 0.2434788962022f);
    glVertex2f(-0.5055772962172f, 0.266868589599f);

    glEnd();
    glPopMatrix();
}
void display3()
{
   // glClearColor(0.0f, 0.f, 0.0f, .0f);
    //glClearColor(1.0f, 0.55f, 0.35f, .0f);
    glClearColor(0.53f, 0.81f, 0.98f, .0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glEnd();

     glBegin(GL_POLYGON);
    //glColor3f(0.15, 0.18, 0.42);
    glColor3f(0.15, 0.18, 0.42);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.28, 0.32, 0.69);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);

    glEnd();

    clouds4(-1.3, 0.0);
    clouds4(-2.3, 0.6);
    clouds4(-0.9, 0.4);
    clouds4(0.3, 0.3);
    clouds4(0.0, 0.0);

    buildings();
    // road
    glBegin(GL_POLYGON);
    glColor3f(0.29f, 0.29f, 0.29f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();


    //upper road
    glBegin(GL_POLYGON);
    glColor3f(0.62f, 0.62f, 0.62f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);

    glEnd();

    //upper road line 1
    glBegin(GL_POLYGON);
    glColor3f(0.84f, 0.84f, 0.84f);
    glVertex2f(-1.0f, -0.335f);
    glVertex2f(1.0f, -0.335f);
    glVertex2f(1.0f, -0.345f);
    glVertex2f(-1.0f, -0.345f);

    glEnd();

    //upper road line 2
    glBegin(GL_POLYGON);
    glColor3f(0.84f, 0.84f, 0.84f);
    glVertex2f(-1.0f, -0.36f);
    glVertex2f(1.0f, -0.36f);
    glVertex2f(1.0f, -0.37f);
    glVertex2f(-1.0f, -0.37f);

    glEnd();




    runway();
    runway2();
    plane();
    plane2();

    glFlush(); // Render now

}


///...........................................................Frame1..................................................///


GLfloat position_car1x = 0.0f;
GLfloat position_bus1x = 0.0f;
GLfloat position_bus2x = 0.0f;
GLfloat position_car1y = 0.0f;
GLfloat position_bus1y = 0.0f;
GLfloat position_bus2y = 0.0f;
GLfloat position_train1x = 0.0f;
GLfloat position_train2x = 0.0f;
GLfloat position_cloud1x = 0.0f;
GLfloat position_cloud2x = 0.0f;
GLfloat position_cloud3x = 0.0f;
GLfloat position_rainY = 0.0f;
GLfloat position_boat1x = 0.0f;
GLfloat position_boat2x = 0.0f;

GLfloat speed = 0.1f;
GLfloat speed1 = 0.01f;
GLfloat speed2 = 0.01f;
GLfloat speedTrain = 0.03f;
GLfloat speedBoat = 0.02f;

//GLfloat speed2 = 0.001f;
# define PI    3.14159265358979323846
using namespace std;


       /**....................................... Cox's Bazar Railway Station ..........................................**/
void train_sound()
{

    PlaySound(TEXT("horn.wav"), NULL, SND_SYNC | SND_FILENAME | SND_LOOP);

}

void circle(float a, float b, float r)
{

    int i;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    GLfloat x=a; GLfloat y=b; GLfloat radius =r;
       glBegin(GL_TRIANGLE_FAN);
       glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}   glEnd();
}







 void motion_vehicle(int value)
{
    if(position_car1x < - 1.5)
            position_car1x = 1.5f;

    if(position_bus1x < - 1.5)
            position_bus1x = 1.5f;

    if(position_bus2x > 1.5)
            position_bus2x = -1.5f;

    if(position_car1y >  0.2)
            position_car1y = - 0.1f;

    if(position_bus1y >  0.2)
            position_bus1y = - 0.1f;

    if(position_bus2y < - 0.2)
            position_bus2y =  0.1f;

    if(position_train1x < -1.5)
            position_train1x = 1.5f;

    if(position_train2x > 1.5)
        position_train2x = -1.5f;

    if(position_cloud1x < - 1.5)
        position_cloud1x = 1.5f;

    if(position_cloud2x > 1.5)
            position_cloud2x = -1.5f;

    if(position_cloud3x > 1.5)
            position_cloud3x = -1.5f;

    if(position_boat1x < - 1.5)
            position_boat1x = 1.5f;

    if(position_boat2x > 1.5)
            position_boat2x = -1.5f;

    position_car1x -= speed;
    position_bus1x -= speed;
    position_bus2x += speed;
    position_car1y +=speed1;
    position_bus1y +=speed1;
    position_bus2y -=speed1;
    position_train1x -= speedTrain;
    position_train2x += speedTrain;
    position_cloud1x -= speed2;
    position_cloud2x += speed2;
    position_cloud3x += speed2;
    position_boat1x -= speedBoat;
    position_boat2x += speedBoat;
	glutPostRedisplay();
	glutTimerFunc(100, motion_vehicle, 0);
}


void motion2_vehicle(int value)
{
    if(position_car1x > 1.5)
            position_car1x = -1.5f;

    if(position_bus1x > 1.5)
            position_bus1x = -1.5f;

    if(position_bus2x < -1.5)
            position_bus2x = 1.5f;

    if(position_car1y < - 0.2)
            position_car1y =  0.1f;

    if(position_bus1y < - 0.2)
            position_bus1y = 0.1f;

    if(position_bus2y >  0.2)
            position_bus2y = - 0.1f;

    if(position_train1x > 1.5)
            position_train1x = -1.5f;

    if(position_train2x < -1.5)
            position_train2x = 1.5f;

    if(position_cloud1x >  1.5)
        position_cloud1x = -1.5f;

    if(position_cloud2x < - 1.5)
            position_cloud2x = 1.5f;

    if(position_cloud3x < - 1.5)
            position_cloud3x = 1.5f;

    if(position_boat1x > 1.5)
            position_boat1x = -1.5f;

    if(position_boat2x < -1.5)
            position_boat2x = 1.5f;





    position_car1x += speed;
    position_bus1x += speed;
    position_bus2x -= speed;
    position_car1y -=speed1;
    position_bus1y -=speed1;
    position_bus2y +=speed1;
    position_train1x += speedTrain;
    position_train2x -= speedTrain;
    position_cloud1x += speed2;
    position_cloud2x -= speed2;
    position_cloud3x -= speed2;
    position_boat1x += speedBoat;
    position_boat2x -= speedBoat;

	glutPostRedisplay();
	glutTimerFunc(100, motion2_vehicle, 0);
}

///.................................Reverse.............................///

 /** void motion_vehicle(int value)
{
    if(position_car1x > 1.5)
            position_car1x = -1.5f;

    if(position_bus1x > 1.5)
            position_bus1x = -1.5f;

    if(position_bus2x < -1.5)
            position_bus2x = 1.5f;

    if(position_car1y < - 0.2)
            position_car1y =  0.1f;

    if(position_bus1y < - 0.2)
            position_bus1y = 0.1f;

    if(position_bus2y >  0.2)
            position_bus2y = - 0.1f;

    if(position_train1x > 1.5)
            position_train1x = -1.5f;

    if(position_train2x < -1.5)
        position_train2x = 1.5f;

    if(position_cloud1x > 1.5)
        position_cloud1x = -1.5f;

    if(position_cloud2x < -1.5)
            position_cloud2x = 1.5f;

    if(position_cloud3x < -1.5)
            position_cloud3x = 1.5f;

    if(position_boat1x > 1.5)
            position_boat1x = -1.5f;

    if(position_boat2x < -1.5)
            position_boat2x = 1.5f;

    position_car1x += speed;
    position_bus1x += speed;
    position_bus2x -= speed;
    position_car1y -= speed1;
    position_bus1y -= speed1;
    position_bus2y += speed1;
    position_train1x += speedTrain;
    position_train2x -= speedTrain;
    position_cloud1x += speed2;
    position_cloud2x -= speed2;
    position_cloud3x -= speed2;
    position_boat1x += speedBoat;
    position_boat2x -= speedBoat;

    glutPostRedisplay();
    glutTimerFunc(100, motion_vehicle, 0);
}

void motion2_vehicle(int value)
{
    if(position_car1x < -1.5)
            position_car1x = 1.5f;

    if(position_bus1x < -1.5)
            position_bus1x = 1.5f;

    if(position_bus2x > 1.5)
            position_bus2x = -1.5f;

    if(position_car1y > 0.2)
            position_car1y = -0.1f;

    if(position_bus1y > 0.2)
            position_bus1y = -0.1f;

    if(position_bus2y < -0.2)
            position_bus2y = 0.1f;

    if(position_train1x < -1.5)
            position_train1x = 1.5f;

    if(position_train2x > 1.5)
            position_train2x = -1.5f;

    if(position_cloud1x < -1.5)
        position_cloud1x = 1.5f;

    if(position_cloud2x > 1.5)
            position_cloud2x = -1.5f;

    if(position_cloud3x > 1.5)
            position_cloud3x = -1.5f;

    if(position_boat1x < -1.5)
            position_boat1x = 1.5f;

    if(position_boat2x > 1.5)
            position_boat2x = -1.5f;

    position_car1x -= speed;
    position_bus1x -= speed;
    position_bus2x += speed;
    position_car1y += speed1;
    position_bus1y += speed1;
    position_bus2y -= speed1;
    position_train1x -= speedTrain;
    position_train2x += speedTrain;
    position_cloud1x -= speed2;
    position_cloud2x += speed2;
    position_cloud3x += speed2;
    position_boat1x -= speedBoat;
    position_boat2x += speedBoat;

    glutPostRedisplay();
    glutTimerFunc(100, motion2_vehicle, 0);
} **/

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            speed = speed + 0.01;
            speed1 = speed1 +0.001;
            speed2 = speed2 +0.001;
            speedTrain = speedTrain +0.003;
            speedBoat = speedBoat +0.002;
            break;

        case GLUT_KEY_DOWN:
            speed = speed - 0.01;
            speed1 = speed1 -0.001;
            speedTrain = speedTrain -0.003;
            speedBoat = speedBoat -0.002;



           break;

        case GLUT_KEY_LEFT:
            glutTimerFunc(100, motion_vehicle, 0);

            train_sound();
            break;

        case GLUT_KEY_RIGHT:
            glutTimerFunc(100, motion2_vehicle, 0);

            break;


         case GLUT_KEY_F1:

            speedTrain = 0.0;

            break;

    default:
        break;
    }
    glutPostRedisplay();
}




void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); ///  Black and opaque
}

void Idle()
{
    glutPostRedisplay();/// marks the current window as needing to be redisplayed
}

   void sea()
{
    /**.......................................Sea ..........................................**/

    glBegin(GL_QUADS);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(-1.0f, 0.66f);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(-1.0f, 0.76f);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(1.0f, 0.76f);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(1.0f, 0.55f);
    glEnd();

    circle(0.1,0.7,0.1);

    /**.......................................Sea Wave ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();

    glPushMatrix();
    glTranslated(0.9f,-0.07f,0.0f);
     glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.4f,0.05f,0.0f);
     glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6f,0.06f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();

    glPushMatrix();
    glTranslated(0.7f,-0.03f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.4f,0.02f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.6f,-0.08f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();

}

void beach()
{
    /**....................................... Beach Sand  ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.404, 0.298);
    glVertex2f(-1.0f, 0.65f);
    glColor3f(0.882, 0.714, 0.522);
    glVertex2f(-1.0f, 0.66f);
    glColor3f(0.58, 0.404, 0.298);
    glVertex2f(1.0f, 0.55f);
    glColor3f(0.882, 0.714, 0.522);
    glVertex2f(1.0f, 0.48f);
    glEnd();

}
void boat1()
{
    /**.......................................Boat 1 ..........................................**/

   glPushMatrix();
   glTranslated(position_boat1x,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.463, 0.486, 0.502);
    glVertex2f(-0.38f, 0.76f);
    glVertex2f(-0.16f, 0.76f);
    glVertex2f(-0.19f, 0.747f);
    glVertex2f(-0.35f, 0.747f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.627f, 0.137f, 0.204f);  // RGB: 160, 35, 52 (Hex: #A02334)
    glVertex2f(-0.26f, 0.83f);
    glVertex2f(-0.33f, 0.77f);
    glVertex2f(-0.26f, 0.77f);

    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3f(0.627f, 0.137f, 0.204f);  // RGB: 160, 35, 52 (Hex: #A02334)
    glVertex2f(-0.26f, 0.86f);
    glVertex2f(-0.22f, 0.77f);
    glVertex2f(-0.26f, 0.76f);

    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.26f, 0.84f);
    glVertex2f(-0.26f, 0.76f);

    glEnd();
    glPopMatrix();


}


void boat2()
{
    /**.......................................Boat 2 ..........................................**/

    glPushMatrix();
    glTranslated(position_boat2x,0.0f,0.0f);
     glBegin(GL_QUADS);
    glColor3f(0.525, 0.286, 0.282);
    glVertex2f(0.6f, 0.71f);
    glVertex2f(0.36f, 0.71f);
    glVertex2f(0.39f, 0.69f);
    glVertex2f(0.57f, 0.69f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.027f, 0.278f, 0.600f);  // RGB: 7, 71, 153 (Hex: #074799)

    glVertex2f(0.48f, 0.78f);
    glVertex2f(0.56f, 0.72f);
    glVertex2f(0.48f, 0.72f);

    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.027f, 0.278f, 0.600f);  // RGB: 7, 71, 153 (Hex: #074799)
    glVertex2f(0.48f, 0.82f);
    glVertex2f(0.44f, 0.72f);
    glVertex2f(0.48f, 0.71f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.48f, 0.79f);
    glVertex2f(0.48f, 0.71f);

    glEnd();
    glPopMatrix();
}



void sky()
{
    /**.......................................Sky ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.576, 0.831, 0.949);
    glVertex2f(-1.0f, 0.76f);
    glColor3f(0.478, 0.78, 0.925);
    glVertex2f(-1.0f, 1.0f);
    glColor3f(0.478, 0.78, 0.925);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.576, 0.831, 0.949);
    glVertex2f(1.0f, 0.76f);
    glEnd();

}

void sun ()
{
    /**.......................................Sun...........................................**/

    GLfloat x=0.7f; GLfloat y=0.85f; GLfloat radius =0.055f;
    int triangleAmount = 100; //# of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glColor3f(1.0f, 0.8235f, 0.0f);  // Orange-Yellow Blend

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // center of circle
        for(i = 0; i <= triangleAmount; i++) {

            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );

            glColor3f(1.0f, 0.8235f, 0.0f);  // Orange-Yellow Blend
        }
    glEnd();


}


void cloud1()
{
     /**........................................Cloud Middle..........................................**/
     glPushMatrix();
     glTranslated(position_cloud1x,0.0f,0.0f);
     glPushMatrix();
     glTranslated(0.0f, 0.05f, 0.0f);
     GLfloat x=0.0f; GLfloat y=0.88f; GLfloat radius =.04f;
     int  triangleAmount = 100;
    GLfloat twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); /// center of circle
    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    x=0.05f;  y=0.88f;  radius =.04f;
    twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    x=-0.05f;  y=0.88f;  radius =.04f;
    twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle
    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    x=-0.04f;  y=0.92f;  radius =.03f;
    twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    x=-0.013f;  y=0.85f;  radius =.03f;
    twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    x=0.053f;  y=0.85f;  radius =.036f;
    twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void cloud2()
{
    /**........................................Cloud Left...........................................**/
    glPushMatrix();
    glTranslated(position_cloud2x,0.0f,0.0f);
    GLfloat x=-0.5f; GLfloat y=0.85f; GLfloat radius =.058f;
    int  triangleAmount = 100;
    GLfloat twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

     x=-0.57f;  y=0.85f;  radius =.037f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle
    for(float i = 0; i <= triangleAmount;i++) {

        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

     x=-0.43f;  y=0.85f;  radius =.04f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

     x=-0.55f;  y=0.86f;  radius =.03f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

     x=-0.61f;  y=0.85f;  radius =.02f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

     x=-0.39f;  y=0.85f;  radius =.02f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }

    glEnd();
    glPopMatrix();
}

void cloud3()
{
     /**........................................Cloud Right...........................................**/
    glPushMatrix();
    glTranslated(position_cloud3x,0.0f,0.0f);
    GLfloat x=0.45f; GLfloat y=0.85f; GLfloat radius =.035f;
    int  triangleAmount = 100;
    GLfloat twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {

        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),

                    y + (radius * sin(i * twicePi / triangleAmount)) );

        }

    glEnd();

     x=0.48f;  y=0.85f;  radius =.03f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

     x=0.42f;  y=0.85f;  radius =.028f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle
    for(float i = 0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
}

 void road()
{

    /**.......................................Road ..........................................**/
    /**....................................... Road color  ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.301, 0.355, 0.35);
    glVertex2f(-1.0f, 0.65f);
    glColor3f(0.301, 0.33, 0.35);
    glVertex2f(1.0f, 0.48f);
    glColor3f(0.302, 0.32, 0.32);
    glVertex2f(1.0f, 0.3f);
    glColor3f(0.301, 0.355, 0.35);
    glVertex2f(-1.0f, 0.55f);
    glEnd();
    /**....................................... Side Divider  ..........................................**/
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-1.0f, 0.64f);
    glVertex2f(1.0f, 0.47f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-1.0f, 0.56f);
    glVertex2f(1.0f, 0.31f);
    glEnd();

    /**....................................... Divider  ..........................................**/
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();
    /**....................................... Continuous Road divider  ..........................................**/
    glPushMatrix();

    glTranslated(0.175f,-0.019f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.019f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.019f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.019f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.015f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.015f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.015f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.018f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.018f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.018f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.018f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

     glPopMatrix();
}

void car()
{
   /**....................................... Car  ..........................................**/
    glPushMatrix();
    glTranslated(position_car1x,position_car1y,0.0f);

    glLineWidth(2);
    glTranslated(-0.9f,0.4f,0.0f);
    glScalef(0.5f,0.5f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.269, 0.541, 0.467);
    glVertex2f(0.9f, 0.35f);
    glVertex2f(0.650f, 0.38f);
    glVertex2f(0.650f, 0.44f);
    glVertex2f(0.7f, 0.440f);
    glVertex2f(0.725f, 0.475f);
    glVertex2f(0.850f, 0.461f);
    glVertex2f(0.880f, 0.416f);
    glVertex2f(0.9f, 0.41f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.753, 0.792, 0.82);
    glVertex2f(0.7f, 0.440f);
    glVertex2f(0.725f, 0.475f);
    glVertex2f(0.850f, 0.461f);
    glVertex2f(0.880f, 0.416f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.7f, 0.440f);
    glVertex2f(0.880f, 0.416f);
    glVertex2f(0.787f, 0.474f);
    glVertex2f(0.782f, 0.36f);
    glEnd();

    /**....................................... Car Tire 1  ..........................................**/

     GLfloat x=0.724f; GLfloat y=0.38f; GLfloat radius =.02f;
	 int triangleAmount = 100; //# of lines used to draw circle
	 GLfloat twicePi = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
	x=0.724f; y=0.38f; radius =.008f;
	triangleAmount = 100; //# of lines used to draw circle
	twicePi = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
    /**....................................... Car Tire 2  ..........................................**/
    x=0.825f; y=0.37f; radius =.02f;
	triangleAmount = 100; //# of lines used to draw circle
	twicePi = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
	x=0.825f; y=0.37f; radius =.008f;
	triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
	glPopMatrix();

}

void bus1()
{
    ///*---------------------------------------Bus 1 -------------------------------------*///
    glPushMatrix();
    glTranslated(position_bus1x,position_bus1y,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.3f, 0.6f);
    glColor3f(0.753, 0.792, 0.82);
    glVertex2f(0.625f, 0.575f);
    glColor3f(0.753, 0.792, 0.82);
    glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.625f, 0.475f);
    glColor3f(0.753, 0.792, 0.82);
    glVertex2f(0.3f, 0.5f);
    glColor3f(0.196, 0.66, 0.64);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.45, 0.69);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.625f, 0.575f);
    glVertex2f(0.625f, 0.550f);
    glVertex2f(0.3f, 0.575f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.45, 0.69);
    glVertex2f(0.3f, 0.550f);
    glVertex2f(0.625f, 0.525f);
    glVertex2f(0.625f, 0.475f);
    glVertex2f(0.3f, 0.5f);
    glEnd();
    /**....................................... Bus 1 Tire 1 ..........................................**/
    GLfloat x=0.350f;GLfloat y=0.5f;GLfloat radius =.02f;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
	x=0.350f; y=0.5f; radius =.008f;
	triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
    /**....................................... Bus 1 Tire 2  ..........................................**/
    x=0.575f; y=0.475f; radius =.02f;
	triangleAmount = 100; //# of lines used to draw circle

	twicePi = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
	x=0.575f; y=0.475f; radius =.008f;
	triangleAmount = 100; //# of lines used to draw circle
	twicePi = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();

    /**....................................... Bus 1 Window  ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glPushMatrix();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();


	///.....................................................................

    glPopMatrix();



    ///.....................
	glPopMatrix();
	glPopMatrix();
	///...............................................

    glPopMatrix();


}

void bus2()
{
    ///*-------------------------------------------Bus 2-------------------------------------------------*///

    glPushMatrix();
    glPushMatrix();
    glTranslated(position_bus2x,position_bus2y,0.0f);
    //glScalef(0.2,0.0,0.0);
    glTranslated(0.4f,-0.13f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.3f, 0.6f);
    glColor3f(0.753, 0.792, 0.82);
    glVertex2f(0.625f, 0.575f);
    glColor3f(0.753, 0.792, 0.82);
    glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.625f, 0.475f);
    glColor3f(0.753, 0.792, 0.82);
    glVertex2f(0.3f, 0.5f);
    glColor3f(0.196, 0.66, 0.64);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.8, 0.89);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.625f, 0.575f);
    glVertex2f(0.625f, 0.550f);
    glVertex2f(0.3f, 0.575f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.8, 0.89);
    glVertex2f(0.3f, 0.550f);
    glVertex2f(0.625f, 0.525f);
    glVertex2f(0.625f, 0.475f);
    glVertex2f(0.3f, 0.5f);
    glEnd();

    /**....................................... Bus 2 Tire 1  ..........................................**/
    GLfloat x=0.350f;GLfloat y=0.5f;GLfloat radius =.02f;
	int triangleAmount = 100; //# of lines used to draw circle
	GLfloat twicePi = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
	x=0.350f; y=0.5f; radius =.008f;
	triangleAmount = 100; //# of lines used to draw circle
	twicePi = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
    /**....................................... Bus 2 Tire 2  ..........................................**/
    x=0.575f; y=0.475f; radius =.02f;
	triangleAmount = 100; //# of lines used to draw circle
	twicePi = 2.0f * PI;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
	x=0.575f; y=0.475f; radius =.008f;
	triangleAmount = 100; //# of lines used to draw circle
	twicePi = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();
    /**....................................... Bus 2 Windows  ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glPushMatrix();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();

    glPopMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.89, 0.886, 0.871);
    glVertex2f(0.4f, 0.567f);
    glVertex2f(0.425f, 0.566f);
    glVertex2f(0.425f, 0.4911f);
    glVertex2f(0.4f, 0.4911f);
    glEnd();
    /**....................................... Bus 2 Door  ..........................................**/

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.4f, 0.567f);
    glVertex2f(0.425f, 0.4911f);
    glEnd();
    glPopMatrix();


    glPopMatrix();

}

void hills()
{
    /**....................................... Hills ..........................................**/

    /**....................................... Hill 1 ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.192, 0.459, 0.192);
    glVertex2f(-0.902f, 0.582f);
    glVertex2f(-0.846f, 0.621f);
    glVertex2f(-0.867f, 0.670f);
    glVertex2f(-0.789f, 0.711f);
    glVertex2f(-0.765f, 0.805f);
    glVertex2f(-0.686f, 0.724f);
    glVertex2f(-0.659f, 0.716f);
    glVertex2f(-0.635f, 0.659f);
    glVertex2f(-0.588f, 0.621f);
    glVertex2f(-0.576f, 0.542f);
    glVertex2f(-0.549f, 0.556f);
    glVertex2f(-0.498f, 0.482f);
    glVertex2f(-0.412f, 0.221f);
    glVertex2f(-0.917f, 0.221f);
    glEnd();

   /**....................................... Hill 1 Shadow  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.791f, 0.714f);
    glVertex2f(-0.763f, 0.742f);
    glVertex2f(-0.776f, 0.761f);
    glVertex2f(-0.744f, 0.756f);
    glVertex2f(-0.713f, 0.718f);
    glVertex2f(-0.746f, 0.722f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.744f, 0.756f);
    glVertex2f(-0.746f, 0.722f);
    glVertex2f(-0.736f, 0.663f);
    glVertex2f(-0.83f, 0.631f);
    glVertex2f(-0.78f, 0.666f);
    glVertex2f(-0.815f, 0.679f);
    glVertex2f(-0.815f, 0.679f);
    glVertex2f(-0.767f, 0.716f);
    glVertex2f(-0.791f, 0.714f);
    glEnd();

    glPushMatrix();
    glTranslated(0.15f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);
    glEnd();
    glPopMatrix();

    /**....................................... Hill 2  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.161, 0.4, 0.169);
    glVertex2f(-1.0f, 0.22f);
    glVertex2f(-1.0f, 0.685f);
    glVertex2f(-0.94f, 0.633f);
    glVertex2f(-0.944f, 0.624f);
    glVertex2f(-0.928f, 0.624f);
    glVertex2f(-0.925f, 0.635f);
    glVertex2f(-0.895f, 0.571f);
    glVertex2f(-0.872f, 0.568f);
    glVertex2f(-0.854f, 0.555f);
    glVertex2f(-0.855f, 0.547f);
    glVertex2f(-0.804f, 0.491f);
    glVertex2f(-0.807f, 0.448f);
    glVertex2f(-0.786f, 0.458f);
    glVertex2f(-0.764f, 0.468f);
    glVertex2f(-0.758f, 0.443f);
    glVertex2f(-0.738f, 0.44f);
    glVertex2f(-0.719f, 0.379f);
    glVertex2f(-0.681f, 0.32f);
    glVertex2f(-0.641f, 0.286f);
    glVertex2f(-0.624f, 0.245f);
    glVertex2f(-0.583f,0.22f);
    glEnd();

    /**....................................... Hill 2 Shadow  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.982f, 0.436f);
    glVertex2f(-0.979f, 0.470f);
    glVertex2f(-0.938f, 0.485f);
    glVertex2f(-0.928f, 0.5224f);
    //glVertex2f(-0.905f, 0.506f);
    glVertex2f(-0.941f, 0.471f);
    glVertex2f(-0.943f, 0.447f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);

    glEnd();

   /**....................................... Hill 3  ..........................................**/

    glPushMatrix();

    glTranslated(0.25f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.02, 0.357, 0.02);

    glVertex2f(-1.0f, 0.22f);
    glVertex2f(-1.0f, 0.38f);
    glVertex2f(-0.903f, 0.468f);
    glVertex2f(-0.889f, 0.465f);
    glVertex2f(-0.835f, 0.555f);
    glVertex2f(-0.816f, 0.594f);
    glVertex2f(-0.759f, 0.547f);
    glVertex2f(-0.758f, 0.557f);
    glVertex2f(-0.724f, 0.521f);
    glVertex2f(-0.7f, 0.526f);
    glVertex2f(-0.697f, 0.503f);
    glVertex2f(-0.661f, 0.482f);
    glVertex2f(-0.66f, 0.475f);
    glVertex2f(-0.64f, 0.474f);
    glVertex2f(-0.559f, 0.354f);
    glVertex2f(-0.528f, 0.347f);
    glVertex2f(-0.462f, 0.218f);
    glEnd();
    glPopMatrix();

    /**....................................... Hill 3 Shadow  ..........................................**/

    glPushMatrix();
    glTranslated(0.1f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.692f, 0.326f);
    glVertex2f(-0.68f, 0.346f);
    glVertex2f(-0.696f, 0.362f);
    glVertex2f(-0.665f, 0.415f);
    glVertex2f(-0.68f, 0.448f);
    glVertex2f(-0.652f, 0.441f);
    glVertex2f(-0.629f, 0.432f);
    glVertex2f(-0.640f, 0.408f);
    glVertex2f(-0.665f, 0.376f);
    glVertex2f(-0.636f, 0.395f);
    glVertex2f(-0.617f, 0.339f);
    glVertex2f(-0.592f, 0.323f);
    glVertex2f(-0.597f, 0.274f);
    glVertex2f(-0.521f, 0.263f);
    glVertex2f(-0.544f, 0.227f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslated(0.2f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.98f, 0.26f);
    glVertex2f(-0.92f, 0.36f);
    glVertex2f(-0.76f, 0.48f);
    glVertex2f(-0.74f, 0.44f);
    glVertex2f(-0.76f, 0.44f);
    glVertex2f(-0.74f, 0.4f);
    glVertex2f(-0.76f, 0.36f);
    glVertex2f(-0.74f, 0.34f);
    glVertex2f(-0.88f, 0.3f);
    glVertex2f(-0.9f, 0.26f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.46f,-0.1f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.56f,-0.2f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);

    glEnd();
    glPopMatrix();



    /**....................................... Hill 4  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.412, 0.102);
    glVertex2f(-1.0f, 0.22f);
    glVertex2f(-1.0f, 0.38f);
    glVertex2f(-0.903f, 0.468f);
    glVertex2f(-0.889f, 0.465f);
    glVertex2f(-0.835f, 0.555f);
    glVertex2f(-0.816f, 0.594f);
    glVertex2f(-0.759f, 0.547f);
    glVertex2f(-0.758f, 0.557f);
    glVertex2f(-0.724f, 0.521f);
    glVertex2f(-0.7f, 0.526f);
    glVertex2f(-0.697f, 0.503f);
    glVertex2f(-0.661f, 0.482f);
    glVertex2f(-0.66f, 0.475f);
    glVertex2f(-0.64f, 0.474f);
    glVertex2f(-0.559f, 0.354f);
    glVertex2f(-0.528f, 0.347f);
    glVertex2f(-0.462f, 0.218f);
    glEnd();

    /**....................................... Hill 4 Shadow  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.98f, 0.26f);
    glVertex2f(-0.92f, 0.36f);
    glVertex2f(-0.76f, 0.48f);
    glVertex2f(-0.74f, 0.44f);
    glVertex2f(-0.76f, 0.44f);
    glVertex2f(-0.74f, 0.4f);
    glVertex2f(-0.76f, 0.36f);
    glVertex2f(-0.74f, 0.34f);
    glVertex2f(-0.88f, 0.3f);
    glVertex2f(-0.9f, 0.26f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.835f, 0.52f);
    glVertex2f(-0.822f, 0.527f);
    glVertex2f(-0.821f, 0.545f);
    glVertex2f(-0.815f, 0.544f);
    glVertex2f(-0.792f, 0.554f);
    glVertex2f(-0.786f, 0.533f);
    glVertex2f(-0.803f, 0.528f);
    glVertex2f(-0.818f, 0.511f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.692f, 0.326f);
    glVertex2f(-0.68f, 0.346f);
    glVertex2f(-0.696f, 0.362f);
    glVertex2f(-0.665f, 0.415f);
    glVertex2f(-0.68f, 0.448f);
    glVertex2f(-0.652f, 0.441f);
    glVertex2f(-0.629f, 0.432f);
    glVertex2f(-0.640f, 0.408f);
    glVertex2f(-0.665f, 0.376f);
    glVertex2f(-0.636f, 0.395f);
    glVertex2f(-0.617f, 0.339f);
    glVertex2f(-0.592f, 0.323f);
    glVertex2f(-0.597f, 0.274f);
    glVertex2f(-0.521f, 0.263f);
    glVertex2f(-0.544f, 0.227f);
    glEnd();
}

void station()
{
    /**....................................... Upper Half Circle Roof ..........................................**/
      GLfloat x=0.0f; GLfloat y=0.3f;GLfloat  radius =.4f;
	   int  triangleAmount = 100; ///# of lines used to draw circle

	    GLfloat twicePi =.892f * PI;
        glColor3f(0.2f, 0.1f, 0.05f);  // Very Dark Brown

	    glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); /// center of circle
		for(float i = 12.6; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
                       glColor3ub(81,66,62);


		}
	    glEnd();



    /**....................................... Upper Roof Stand 1 ..........................................**/
    glLineWidth(4);
     x=0.0f;  y=0.3f;  radius =0.36f;
	float i;
	int lineAmount = 100; //# of triangles used to draw circle

	 twicePi = .891f * PI;

    glColor3f(0.478, 0.478, 0.463);
	glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
		for(i = 12.7; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
    /**....................................... Upper Roof Stand 2 ..........................................**/
	  x=0.0f;  y=0.3f;  radius =0.4f;

	 lineAmount = 100; //# of triangles used to draw circle


	 twicePi = 1.05f * PI;

    glColor3f(0.478, 0.478, 0.463);
	glBegin(GL_LINE_LOOP);
		for(i = -4; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();


    /**....................................... Upper Roof Stand 3  ..........................................**/
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-0.375f, 0.437f);
    glVertex2f(-0.27f, 0.2f);

    glVertex2f(0.375f, 0.437f);
    glVertex2f(0.27f, 0.2f);
    glEnd();

    /**....................................... Upper Roof Stand 4 ..........................................**/
    glLineWidth(2);
	  x=0.0f;  y=0.11f;  radius =0.4f;

	 lineAmount = 100; //# of triangles used to draw circle


	 twicePi = 1.0f * PI;

    glColor3f(0.2f, 0.1f, 0.05f);  // Very Dark Brown
	glBegin(GL_LINE_LOOP);
		for(i = 1; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
    /**....................................... Upper Roof Stand 5 ..........................................**/
    glLineWidth(2);
	  x=0.0f;  y=0.099f;  radius =0.4f;

	 lineAmount = 100; //# of triangles used to draw circle


	 twicePi = 1.0f * PI;

    glColor3f(0.2f, 0.1f, 0.05f);  // Very Dark Brown
	glBegin(GL_LINE_LOOP);
		for(i = 1; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	/**....................................... Upper Roof Stand 6 ..........................................**/
    glLineWidth(2);
	  x=0.0f;  y=0.089f;  radius =0.4f;

	 lineAmount = 100; //# of triangles used to draw circle


	 twicePi = 1.0f * PI;

    glColor3f(0.2f, 0.1f, 0.05f);  // Very Dark Brown
	glBegin(GL_LINE_LOOP);
		for(i = 1; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

		/**....................................... Upper Roof Stand 7 ..........................................**/
    glLineWidth(2);
	  x=0.0f;  y=0.079f;  radius =0.4f;

	 lineAmount = 100; //# of triangles used to draw circle


	 twicePi = 1.0f * PI;

    glColor3f(0.2f, 0.1f, 0.05f);  // Very Dark Brown
	glBegin(GL_LINE_LOOP);
		for(i = 1; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

    	/**....................................... Upper Roof Stand 8 ..........................................**/
    glLineWidth(2);
	  x=0.0f;  y=0.069f;  radius =0.4f;

	 lineAmount = 100; //# of triangles used to draw circle


	 twicePi = 1.0f * PI;

    glColor3f(0.2f, 0.1f, 0.05f);  // Very Dark Brown
	glBegin(GL_LINE_LOOP);
		for(i = 1; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
    	/**....................................... Upper Roof Stand 9 ..........................................**/
    glLineWidth(2);
	  x=0.0f;  y=0.059f;  radius =0.4f;

	 lineAmount = 100; //# of triangles used to draw circle


	 twicePi = 1.0f * PI;

    glColor3f(0.2f, 0.1f, 0.05f);  // Very Dark Brown
	glBegin(GL_LINE_LOOP);
		for(i = 1; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
    /**....................................... Upper Roof Stand 10 ..........................................**/
    glLineWidth(2);
	  x=0.0f;  y=0.049f;  radius =0.4f;

	 lineAmount = 100; //# of triangles used to draw circle


	 twicePi = 1.0f * PI;

    glColor3f(0.2f, 0.1f, 0.05f);  // Very Dark Brown
	glBegin(GL_LINE_LOOP);
		for(i = 1; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
    /**....................................... Upper Roof stand ..........................................**/
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.478, 0.478, 0.463);
    glVertex2f(-0.36f, 0.47f);
    glVertex2f(-0.3f, 0.41f);

    glVertex2f(-0.35f, 0.5f);
    glVertex2f(-0.25f, 0.4f);

    glVertex2f(-0.333f, 0.53f);
    glVertex2f(-0.20f, 0.4f);

    glVertex2f(-0.31f, 0.56f);
    glVertex2f(-0.15f, 0.4f);

    glVertex2f(-0.285f, 0.585f);
    glVertex2f(-0.10f, 0.4f);

    glVertex2f(-0.255f, 0.61f);
    glVertex2f(-0.05f, 0.405f);

    glVertex2f(-0.225f, 0.635f);
    glVertex2f(-0.0f, 0.41f);

    glVertex2f(-0.19f, 0.655f);
    glVertex2f(0.05f, 0.41f);

    glVertex2f(-0.15f, 0.675f);
    glVertex2f(0.10f, 0.41f);

    glVertex2f(-0.105f, 0.69f);
    glVertex2f(0.15f, 0.41f);

    glVertex2f(-0.057f, 0.7f);
    glVertex2f(0.20f, 0.41f);

    glVertex2f(0.36f, 0.47f);
    glVertex2f(0.3f, 0.41f);

    glVertex2f(0.35f, 0.5f);
    glVertex2f(0.25f, 0.4f);

    glVertex2f(0.333f, 0.53f);
    glVertex2f(0.20f, 0.4f);

    glVertex2f(0.31f, 0.56f);
    glVertex2f(0.15f, 0.4f);

    glVertex2f(0.285f, 0.585f);
    glVertex2f(0.10f, 0.4f);

    glVertex2f(0.255f, 0.61f);
    glVertex2f(0.05f, 0.405f);

    glVertex2f(0.225f, 0.635f);
    glVertex2f(0.0f, 0.41f);

    glVertex2f(0.19f, 0.655f);
    glVertex2f(-0.05f, 0.41f);

    glVertex2f(0.15f, 0.675f);
    glVertex2f(-0.10f, 0.41f);

    glVertex2f(0.105f, 0.69f);
    glVertex2f(-0.15f, 0.41f);

    glVertex2f(0.057f, 0.7f);
    glVertex2f(-0.20f, 0.41f);

    glVertex2f(0.00f, 0.7f);
    glVertex2f(0.00f, 0.4f);


    glEnd();


    /**....................................... Side Glass Wall Left ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.627, 0.792, 0.816);
    glVertex2f(-0.27f, 0.4f);
    glColor3f(0.561, 0.89, 0.941);
    glVertex2f(-0.17f, 0.4f);
    glColor3f(0.306, 0.518, 0.549);
    glVertex2f(-0.17f, 0.26f);
    glColor3f(0.478, 0.686, 0.722);
    glVertex2f(-0.23f, 0.26f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.643, 0.663, 0.675);
    glVertex2f(-0.19f, 0.26f);
    glVertex2f(-0.19f, 0.4f);
    glVertex2f(-0.21f, 0.26f);
    glVertex2f(-0.21f, 0.4f);
    glVertex2f(-0.23f, 0.26f);
    glVertex2f(-0.23f, 0.4f);
    glVertex2f(-0.25f, 0.335f);
    glVertex2f(-0.25f, 0.4f);
    glVertex2f(-0.17f, 0.27f);
    glVertex2f(-0.23f, 0.27f);
    glVertex2f(-0.17f, 0.28f);
    glVertex2f(-0.24f, 0.28f);
    glVertex2f(-0.17f, 0.29f);
    glVertex2f(-0.24f, 0.29f);
    glVertex2f(-0.17f, 0.30f);
    glVertex2f(-0.24f, 0.30f);
    glVertex2f(-0.17f, 0.31f);
    glVertex2f(-0.24f, 0.31f);
    glVertex2f(-0.17f, 0.32f);
    glVertex2f(-0.24f, 0.32f);
    glVertex2f(-0.17f, 0.33f);
    glVertex2f(-0.251f, 0.33f);
    glVertex2f(-0.17f, 0.34f);
    glVertex2f(-0.254f, 0.34f);
    glVertex2f(-0.17f, 0.35f);
    glVertex2f(-0.257f, 0.35f);
    glVertex2f(-0.17f, 0.36f);
    glVertex2f(-0.259f, 0.36f);
    glVertex2f(-0.17f, 0.37f);
    glVertex2f(-0.262f, 0.37f);
    glVertex2f(-0.17f, 0.38f);
    glVertex2f(-0.265f, 0.38f);
    glVertex2f(-0.17f, 0.39f);
    glVertex2f(-0.267f, 0.39f);
    glEnd();



    /**....................................... Side Glass Wall Left ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.627, 0.792, 0.816);
    glVertex2f(0.27f, 0.4f);
    glColor3f(0.478, 0.686, 0.722);
    glVertex2f(0.17f, 0.4f);
    glColor3f(0.306, 0.518, 0.549);
    glVertex2f(0.17f, 0.26f);
    glColor3f(0.561, 0.89, 0.941);
    glVertex2f(0.23f, 0.26f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.643, 0.663, 0.675);
    glVertex2f(0.19f, 0.26f);
    glVertex2f(0.19f, 0.4f);
    glVertex2f(0.21f, 0.26f);
    glVertex2f(0.21f, 0.4f);
    glVertex2f(0.23f, 0.26f);
    glVertex2f(0.23f, 0.4f);
    glVertex2f(0.25f, 0.335f);
    glVertex2f(0.25f, 0.4f);
    glVertex2f(0.17f, 0.27f);
    glVertex2f(0.234f, 0.27f);
    glVertex2f(0.17f, 0.28f);
    glVertex2f(0.237f, 0.28f);
    glVertex2f(0.17f, 0.29f);
    glVertex2f(0.24f, 0.29f);
    glVertex2f(0.17f, 0.30f);
    glVertex2f(0.24f, 0.30f);
    glVertex2f(0.17f, 0.31f);
    glVertex2f(0.24f, 0.31f);
    glVertex2f(0.17f, 0.32f);
    glVertex2f(0.24f, 0.32f);
    glVertex2f(0.17f, 0.33f);
    glVertex2f(0.251f, 0.33f);
    glVertex2f(0.17f, 0.34f);
    glVertex2f(0.254f, 0.34f);
    glVertex2f(0.17f, 0.35f);
    glVertex2f(0.257f, 0.35f);
    glVertex2f(0.17f, 0.36f);
    glVertex2f(0.259f, 0.36f);
    glVertex2f(0.17f, 0.37f);
    glVertex2f(0.262f, 0.37f);
    glVertex2f(0.17f, 0.38f);
    glVertex2f(0.265f, 0.38f);
    glVertex2f(0.17f, 0.39f);
    glVertex2f(0.267f, 0.39f);
    glEnd();
    /**....................................... Top Glass roof ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.627, 0.792, 0.816);
    glVertex2f(-0.19f, 0.38f);
    glColor3f(0.478, 0.686, 0.722);
    glVertex2f(-0.19f, 0.5f);
    glColor3f(0.561, 0.89, 0.941);
    glVertex2f(0.19f, 0.5f);
    glColor3f(0.306, 0.518, 0.549);
    glVertex2f(0.19f, 0.38f);
    glEnd();
    /**....................................... Top Glass Roof Joining Aluminium frame..........................................**/
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.643, 0.663, 0.675);
    glVertex2f(-0.19f, 0.39f);
    glVertex2f(0.19f, 0.39f);
    glVertex2f(-0.19f, 0.40f);
    glVertex2f(0.19, 0.40f);
    glVertex2f(-0.19f, 0.41f);
    glVertex2f(0.19f, 0.41f);
    glVertex2f(-0.19f, 0.42f);
    glVertex2f(0.19f, 0.42f);
    glVertex2f(-0.19f, 0.43f);
    glVertex2f(0.19f, 0.43f);
    glVertex2f(-0.19f, 0.44f);
    glVertex2f(0.19f, 0.44f);
    glVertex2f(-0.19f, 0.45f);
    glVertex2f(0.19f, 0.45f);
    glVertex2f(-0.19f, 0.46f);
    glVertex2f(0.19f, 0.46f);
    glVertex2f(-0.19f, 0.47f);
    glVertex2f(0.19f, 0.47f);
    glVertex2f(-0.19f, 0.48f);
    glVertex2f(0.19f, 0.48f);
    glVertex2f(-0.19f, 0.49f);
    glVertex2f(0.19f, 0.49f);
    glVertex2f(-0.17f, 0.50f);
    glVertex2f(-0.17f, 0.38f);
    glVertex2f(-0.15f, 0.50f);
    glVertex2f(-0.15f, 0.38f);
    glVertex2f(-0.13f, 0.5f);
    glVertex2f(-0.13f, 0.38f);
    glVertex2f(-0.11f, 0.5f);
    glVertex2f(-0.11f, 0.38f);
    glVertex2f(-0.09f, 0.5f);
    glVertex2f(-0.09f, 0.38f);
    glVertex2f(-0.07f, 0.5f);
    glVertex2f(-0.07f, 0.38f);
    glVertex2f(-0.05f, 0.5f);
    glVertex2f(-0.05f, 0.38f);
    glVertex2f(-0.03f, 0.5f);
    glVertex2f(-0.03f, 0.38f);
    glVertex2f(-0.01f, 0.5f);
    glVertex2f(-0.01f, 0.38f);
    glVertex2f(0.01f, 0.50f);
    glVertex2f(0.01f, 0.38f);
    glVertex2f(0.03f, 0.50f);
    glVertex2f(0.03f, 0.38f);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(0.05f, 0.38f);
    glVertex2f(0.07f, 0.5f);
    glVertex2f(0.07f, 0.38f);
    glVertex2f(0.09f, 0.5f);
    glVertex2f(0.09f, 0.38f);
    glVertex2f(0.11f, 0.5f);
    glVertex2f(0.11f, 0.38f);
    glVertex2f(0.13f, 0.50f);
    glVertex2f(0.13f, 0.38f);
    glVertex2f(0.15f, 0.5f);
    glVertex2f(0.15f, 0.38f);
    glVertex2f(0.17f, 0.5f);
    glVertex2f(0.17f, 0.38f);

    glEnd();



    /**....................................... Terminal ..........................................**/

    ///  2 side wall
    glBegin(GL_QUADS);
    glColor3f(0.698, 0.596, 0.592);
    glVertex2f(-0.17f, 0.26f);
    glVertex2f(-0.17f, 0.38f);
    glVertex2f(0.17f, 0.38f);
    glVertex2f(0.17f, 0.26f);
    glEnd();
    ///  Terminal Glass
    glBegin(GL_QUADS);
    glColor3f(0.824, 0.847, 0.839);
    glVertex2f(-0.1f, 0.26f);
    glColor3f(0.702, 0.812, 0.776);
    glVertex2f(-0.1f, 0.38f);
    glColor3f(0.937, 0.937, 0.937);
    glVertex2f(0.1f, 0.38f);
    glColor3f(0.863, 0.902, 0.898);
    glVertex2f(0.1f, 0.26f);
    glEnd();
    /**....................................... Terminal Glass Joining Aluminium frame..........................................**/
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.643, 0.663, 0.675);
    glVertex2f(-0.1f, 0.27f);
    glVertex2f(0.1f, 0.27f);
    glVertex2f(-0.1f, 0.28f);
    glVertex2f(0.1f, 0.28f);
    glVertex2f(-0.1f, 0.29f);
    glVertex2f(0.1f, 0.29f);
    glVertex2f(-0.1f, 0.30f);
    glVertex2f(0.1f, 0.30f);
    glVertex2f(-0.1f, 0.31f);
    glVertex2f(0.1f, 0.31f);
    glVertex2f(-0.1f, 0.32f);
    glVertex2f(0.1f, 0.32f);
    glVertex2f(-0.1f, 0.33f);
    glVertex2f(0.1f, 0.33f);
    glVertex2f(-0.1f, 0.34f);
    glVertex2f(0.1f, 0.34f);
    glVertex2f(-0.1f, 0.35f);
    glVertex2f(0.1f, 0.35f);
    glVertex2f(-0.1f, 0.36f);
    glVertex2f(0.1f, 0.36f);
    glVertex2f(-0.1f, 0.37f);
    glVertex2f(0.1f, 0.37f);
    glVertex2f(-0.09f, 0.26f);
    glVertex2f(-0.09f, 0.38f);
    glVertex2f(-0.08f, 0.26f);
    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.07f, 0.26f);
    glVertex2f(-0.07f, 0.38f);
    glVertex2f(-0.06f, 0.26f);
    glVertex2f(-0.06f, 0.38f);
    glVertex2f(-0.05f, 0.26f);
    glVertex2f(-0.05f, 0.38f);
    glVertex2f(-0.04f, 0.26f);
    glVertex2f(-0.04f, 0.38f);
    glVertex2f(-0.03f, 0.26f);
    glVertex2f(-0.03f, 0.38f);
    glVertex2f(-0.02f, 0.26f);
    glVertex2f(-0.02f, 0.38f);
    glVertex2f(-0.01f, 0.26f);
    glVertex2f(-0.01f, 0.38f);
    glVertex2f(0.0f, 0.26f);
    glVertex2f(0.0f, 0.38f);
    glVertex2f(0.01f, 0.26f);
    glVertex2f(0.01f, 0.38f);
    glVertex2f(0.02f, 0.26f);
    glVertex2f(0.02f, 0.38f);
    glVertex2f(0.03f, 0.26f);
    glVertex2f(0.03f, 0.38f);
    glVertex2f(0.04f, 0.26f);
    glVertex2f(0.04f, 0.38f);
    glVertex2f(0.05f, 0.26f);
    glVertex2f(0.05f, 0.38f);
    glVertex2f(0.06f, 0.26f);
    glVertex2f(0.06f, 0.38f);
    glVertex2f(0.07f, 0.26f);
    glVertex2f(0.07f, 0.38f);
    glVertex2f(0.08f, 0.26f);
    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.09f, 0.26f);
    glVertex2f(0.09f, 0.38f);
    glEnd();
    /**....................................... Gate ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(-0.02f, 0.26f);
    glVertex2f(-0.02f, 0.35f);
    glVertex2f(0.04f, 0.35f);
    glVertex2f(0.04f, 0.26f);
    glEnd();

    ///  Gate Joining Aluminium frame
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.643, 0.663, 0.675);
    glVertex2f(0.01f, 0.26f);
    glVertex2f(0.01f, 0.35f);
    glVertex2f(-0.02f, 0.29f);
    glVertex2f(0.04f, 0.29f);
    glEnd();

    /**....................................... Roof Supporting Stand ..........................................**/
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.478, 0.478, 0.463);

    glVertex2f(-0.32f, 0.47f);
    glVertex2f(-0.29f, 0.33f);
    glVertex2f(-0.32f, 0.47f);
    glVertex2f(-0.32f, 0.33f);

    /*glVertex2f(-0.303f, 0.50f);
    glVertex2f(-0.27f, 0.33f);
    glVertex2f(-0.303f, 0.50f);
    glVertex2f(-0.24f, 0.33f);*/

    glVertex2f(-0.28f, 0.53f);
    glVertex2f(-0.22f, 0.33f);
    glVertex2f(-0.28f, 0.53f);
    glVertex2f(-0.19f, 0.33f);

    /*glVertex2f(-0.255f, 0.555f);
    glVertex2f(-0.17f, 0.33f);
    glVertex2f(-0.255f, 0.555f);
    glVertex2f(-0.14f, 0.33f);*/

    glVertex2f(-0.225f, 0.583f);
    glVertex2f(-0.12f, 0.33f);
    glVertex2f(-0.225f, 0.583f);
    glVertex2f(-0.09f, 0.33f);

    /*glVertex2f(-0.195f, 0.603f);
    glVertex2f(-0.07f, 0.33f);
    glVertex2f(-0.195f, 0.603f);
    glVertex2f(-0.04f, 0.33f);*/

    glVertex2f(-0.16f, 0.623f);
    glVertex2f(-0.02f, 0.33f);
    glVertex2f(-0.16f, 0.623f);
    glVertex2f(0.01f, 0.33f);

    /*glVertex2f(-0.12f, 0.643f);
    glVertex2f(0.03f, 0.33f);
    glVertex2f(-0.12f, 0.643f);
    glVertex2f(0.06f, 0.33f);*/

    glVertex2f(-0.075f, 0.655f);
    glVertex2f(0.08f, 0.33f);
    glVertex2f(-0.075f, 0.655f);
    glVertex2f(0.11f, 0.33f);

    /*glVertex2f(-0.025f, 0.66f);
    glVertex2f(0.13f, 0.33f);
    glVertex2f(-0.025f, 0.66f);
    glVertex2f(0.16f, 0.33f);*/

    glVertex2f(0.0f, 0.66f);
    glVertex2f(-0.45f, 0.33f);
    glVertex2f(0.0f, 0.66f);
    glVertex2f(0.45f, 0.33f);


    glVertex2f(0.32f, 0.47f);
    glVertex2f(0.29f, 0.33f);
    glVertex2f(0.32f, 0.47f);
    glVertex2f(0.32f, 0.33f);

    /*glVertex2f(0.303f, 0.50f);
    glVertex2f(0.27f, 0.33f);
    glVertex2f(0.303f, 0.50f);
    glVertex2f(0.24f, 0.33f);*/

    glVertex2f(0.28f, 0.53f);
    glVertex2f(0.22f, 0.33f);
    glVertex2f(0.28f, 0.53f);
    glVertex2f(0.19f, 0.33f);

    /*glVertex2f(0.255f, 0.555f);
    glVertex2f(0.17f, 0.33f);
    glVertex2f(0.255f, 0.555f);
    glVertex2f(0.14f, 0.33f);*/

    glVertex2f(0.225f, 0.583f);
    glVertex2f(0.12f, 0.33f);
    glVertex2f(0.225f, 0.583f);
    glVertex2f(0.09f, 0.33f);

    /*glVertex2f(0.195f, 0.603f);
    glVertex2f(0.07f, 0.33f);
    glVertex2f(0.195f, 0.603f);
    glVertex2f(0.04f, 0.33f);*/

    glVertex2f(0.16f, 0.623f);
    glVertex2f(0.02f, 0.33f);
    glVertex2f(0.16f, 0.623f);
    glVertex2f(-0.01f, 0.33f);

    /*glVertex2f(0.12f, 0.643f);
    glVertex2f(-0.03f, 0.33f);
    glVertex2f(0.12f, 0.643f);
    glVertex2f(-0.06f, 0.33f);*/

    glVertex2f(0.075f, 0.655f);
    glVertex2f(-0.08f, 0.33f);
    glVertex2f(0.075f, 0.655f);
    glVertex2f(-0.11f, 0.33f);

    /*glVertex2f(0.025f, 0.66f);
    glVertex2f(-0.13f, 0.33f);
    glVertex2f(0.025f, 0.66f);
    glVertex2f(-0.16f, 0.33f);*/

    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    renderBitmapString(-0.16f, 0.550f, 0.0f, GLUT_BITMAP_HELVETICA_18, "COX'S Bazar Railway Station");
}

void rail_Line()
{
    /**....................................... Rail Line Stone ..........................................**/
    glBegin(GL_QUADS);
    ///    Upper
    glColor3f(0.537, 0.569, 0.592);
    glVertex2f(-1.0f, 0.03f);
    glColor3f(0.553, 0.584, 0.635);
    glVertex2f(-1.0f, 0.09f);
    glColor3f(0.235, 0.365, 0.459);
    glVertex2f(1.0f, 0.09f);
    glColor3f(0.486, 0.388, 0.267);
    glVertex2f(1.0f, 0.03f);
    ///     lower
    glColor3f(0.537, 0.569, 0.592);
    glVertex2f(-1.0f, 0.11f);
    glColor3f(0.553, 0.584, 0.635);
    glVertex2f(-1.0f, 0.17f);
    glColor3f(0.235, 0.365, 0.459);
    glVertex2f(1.0f, 0.17f);
    glColor3f(0.486, 0.388, 0.267);
    glVertex2f(1.0f, 0.11f);
    glEnd();

    /**....................................... Rail Line Soil ..........................................**/
    glBegin(GL_QUADS);
    ///      Middle
    glColor3f(0.663, 0.447, 0.29);
    glVertex2f(-1.0f, 0.09f);
    glColor3f(0.322, 0.22, 0.188);
    glVertex2f(-1.0f, 0.11f);
    glColor3f(0.855, 0.686, 0.4940);
    glVertex2f(1.0f, 0.11f);
    glColor3f(0.678, 0.467, 0.294);
    glVertex2f(1.0f, 0.09f);
    ///    Lower
    glColor3f(0.855, 0.686, 0.4940);
    glVertex2f(-1.0f, 0.0f);
    glColor3f(0.678, 0.467, 0.294);
    glVertex2f(-1.0f, 0.03f);
    glColor3f(0.322, 0.22, 0.188);
    glVertex2f(1.0f, 0.03f);
    glColor3f(0.663, 0.447, 0.29);
    glVertex2f(1.0f, 0.00f);
    ///    Upper
    glColor3f(0.678, 0.467, 0.294);
    glVertex2f(-1.0f, 0.17f);
    glColor3f(0.855, 0.686, 0.4940);
    glVertex2f(-1.0f, 0.22f);
    glColor3f(0.322, 0.22, 0.188);
    glVertex2f(1.0f, 0.22f);
    glColor3f(0.663, 0.447, 0.29);
    glVertex2f(1.0f, 0.17f);

    glEnd();



    /**....................................... Rail Line ..........................................**/
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    ///     Lower Line
    glVertex2f(-1.0f, 0.04f);
    glVertex2f(1.0f, 0.04f);
    glVertex2f(-1.0f, 0.08f);
    glVertex2f(1.0f, 0.08f);
    ///     Upper Line
    glVertex2f(-1.0f, 0.12f);
    glVertex2f(1.0f, 0.12f);
    glVertex2f(-1.0f, 0.16f);
    glVertex2f(1.0f, 0.16f);
    glEnd();

    /**....................................... Lower Line Joiner ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
     glVertex2f(-1.01f, 0.04f);
    glVertex2f(-0.98f, 0.08f);

    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);

    glEnd();
    glPushMatrix();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);

    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();

    glPopMatrix();

    /**....................................... Upper Line Joiner ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
     glVertex2f(-1.01f, 0.12f);
    glVertex2f(-0.98f, 0.16f);

    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);

    glEnd();
    glPushMatrix();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);

    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();

    glPopMatrix();

}

void rail_Line1(){

    glPushMatrix();

    // Second Rail Track (-y direction)
    glPushMatrix();
    glTranslatef(0.0f, -0.3f, 0.0f);

    // Rail Line Soil (Darker brown)
    glBegin(GL_QUADS);
    glColor3f(0.663, 0.447, 0.29);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(-1.0f, 0.1f);
    glEnd();

    // Middle Rail Line (Darker gray)
    glBegin(GL_QUADS);
    glColor3f(0.537, 0.569, 0.592); // Color for the middle rail (Light gray)
    glVertex2f(-1.0f, 0.05f);
    glVertex2f(1.0f, 0.05f);
    glVertex2f(1.0f, -0.05f);
    glVertex2f(-1.0f, -0.05f);
    glEnd();

    // Rail Line (Darker gray)
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);  // Charcoal color for rail line
    glVertex2f(-1.0f, 0.04f);
    glVertex2f(1.0f, 0.04f);
    glVertex2f(-1.0f, -0.04f);
    glVertex2f(1.0f, -0.04f);
    glEnd();

    // Rail Line Joiners (Charcoal Brown)
    for (float x = -1.01f; x < 1.0f; x += 0.04f) {
        glBegin(GL_LINES);
        glColor3f(0.114f, 0.106f, 0.125f);  // Charcoal Brown color
        glVertex2f(x, -0.04f);
        glVertex2f(x + 0.03f, 0.04f);
        glEnd();
    }
    glPopMatrix();

    // Third Rail Track (-y direction)
    glPushMatrix();
    glTranslatef(0.0f, -0.6f, 0.0f);

    // Rail Line Soil (Darker brown)
    glBegin(GL_QUADS);
    glColor3f(0.663, 0.447, 0.29);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(-1.0f, 0.1f);
    glEnd();

    // Middle Rail Line (Light gray)
    glBegin(GL_QUADS);
    glColor3f(0.537, 0.569, 0.592); // Color for the middle rail (Light gray)
    glVertex2f(-1.0f, 0.05f);
    glVertex2f(1.0f, 0.05f);
    glVertex2f(1.0f, -0.05f);
    glVertex2f(-1.0f, -0.05f);
    glEnd();

    // Rail Line (Darker gray)
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);  // Charcoal color for rail line
    glVertex2f(-1.0f, 0.04f);
    glVertex2f(1.0f, 0.04f);
    glVertex2f(-1.0f, -0.04f);
    glVertex2f(1.0f, -0.04f);
    glEnd();

    // Rail Line Joiners (Charcoal Brown)
    for (float x = -1.01f; x < 1.0f; x += 0.04f) {
        glBegin(GL_LINES);
        glColor3f(0.114f, 0.106f, 0.125f);  // Charcoal Brown color
        glVertex2f(x, -0.04f);
        glVertex2f(x + 0.03f, 0.04f);
        glEnd();
    }
    glPopMatrix();
}





void platform()
{
        /**....................................... Barricade ..........................................**/

    /**....................................... Barricade stand ..........................................**/
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();

    glPushMatrix();

    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();

    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.22f);
    glVertex2f(0.5f, 0.28f);
    glEnd();

    glPopMatrix();

    glBegin(GL_LINES);
    glVertex2f(0.48f, 0.24f);
    glVertex2f(1.0f, 0.24f);
    glVertex2f(0.48f, 0.26f);
    glVertex2f(1.0f, 0.26f);
    glEnd();

    /**....................................... Barricade Triangle ..........................................**/
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glPushMatrix();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glTranslated(0.03f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.49f, 0.28f);
    glVertex2f(0.51f, 0.28f);
    glVertex2f(0.50f, 0.29f);
    glEnd();
    glPopMatrix();

    /**....................................... Platform ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.251, 0.212, 0.231);
    glVertex2f(-1.0f, 0.18f);
    glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
    glVertex2f(1.0f, 0.18f);
    glEnd();

    /// Middle Section (Extended from -1.0 to 1.0)
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.549, 0.498);
    glVertex2f(-1.0f, 0.2f);
    glVertex2f(-1.0f, 0.22f);
    glVertex2f(1.0f, 0.22f);
    glVertex2f(1.0f, 0.2f);
    glEnd();

    /// Upper Section (Extended from -1.0 to 1.0)
    glBegin(GL_QUADS);
    glColor3f(0.616, 0.608, 0.6);
    glVertex2f(-1.0f, 0.22f);
    glVertex2f(-0.98f, 0.26f);
    glVertex2f(0.98f, 0.26f);
    glVertex2f(1.0f, 0.22f);
    glEnd();

    /// Red Mark (Danger Line)
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.8f, 0.0f, 0.0f);  // Dark Red
    glVertex2f(-1.0f, 0.22f);
    glVertex2f(1.0f, 0.22f);
    glEnd();

    /// Side Structure (Extended to full width)
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.549, 0.498);
    glVertex2f(1.0f, 0.18f);
    glVertex2f(1.0f, 0.22f);
    glVertex2f(0.98f, 0.26f);
    glVertex2f(0.98f, 0.22f);
    glEnd();

    /// Yellow Safety Line (Extended to full width)
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.906, 0.91, 0.2);
    glVertex2f(-1.0f, 0.23f);
    glVertex2f(1.0f, 0.23f);
    glEnd();

    /**....................................... Platform Roof ..........................................**/

    ///up
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(-0.98f, 0.3f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(-0.98f, 0.33f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(0.98f, 0.33f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(0.98f, 0.3f);


    /**....................................... Platform Pillar ..........................................**/

    ///       Straight Piller
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(-0.05f, 0.24f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(-0.05f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(-0.03f, 0.3f);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(-0.03f, 0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.07f, 0.24f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(0.07f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(0.05f, 0.3f);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.05f, 0.24f);
    glEnd();

    ///      Another pillers

    glPushMatrix();
    glTranslated(0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(-0.02f, 0.3f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(-0.02f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(-0.02f, 0.3f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(-0.02f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(-0.02f, 0.3f);
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(-0.02f, 0.3f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(-0.02f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(-0.02f, 0.3f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(-0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(-0.02f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();


    glTranslated(-0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(-0.02f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(-0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(-0.02f, 0.3f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(-0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glVertex2f(-0.02f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(-0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(-0.02f, 0.3f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(-0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(-0.02f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();

    glTranslated(-0.13f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.424, 0.341, 0.282);
    glVertex2f(0.0f, 0.24f);
    glColor3f(1.0f, 1.0f, 0.8f); // Light Yellowish Color
    glVertex2f(-0.02f, 0.3f);
    glColor3f(0.3f, 0.2f, 0.1f);  // Deeper Dark Brown
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.02f, 0.24f);
    glEnd();



    glPopMatrix();

}

void tree1()///small tree
{
    /**....................................... Small Tree (right) ..........................................**/

    /**....................................... Small Tree (right) Stem ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.54f, 0.20f);
    glVertex2f(0.54f, 0.25f);
    glVertex2f(0.56f, 0.25f);
    glVertex2f(0.56f, 0.20f);
    glEnd();
    /**....................................... Small Tree (right) Leaf ..........................................**/
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.235, 0.039);
    glVertex2f(0.47f, 0.25f);
    glVertex2f(0.63f, 0.25f);
    glVertex2f(0.55f, 0.34f);

    glColor3f(0.008, 0.357, 0.063);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.55f, 0.38f);

    glColor3f(0.024, 0.451, 0.086);
    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.55f, 0.42f);
    glEnd();
    /**....................................... Small Tree (Left) ..........................................**/
    glPushMatrix();
    glTranslated(-1.1f,0.0f,0.0f);
    /**....................................... Small Tree (Left) Stem ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.54f, 0.20f);
    glVertex2f(0.54f, 0.25f);
    glVertex2f(0.56f, 0.25f);
    glVertex2f(0.56f, 0.20f);
    glEnd();
    /**....................................... Small Tree (Left) Leaf ..........................................**/
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.235, 0.039);
    glVertex2f(0.47f, 0.25f);
    glVertex2f(0.63f, 0.25f);
    glVertex2f(0.55f, 0.34f);

    glColor3f(0.008, 0.357, 0.063);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.55f, 0.38f);

    glColor3f(0.024, 0.451, 0.086);
    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.55f, 0.42f);
    glEnd();
    glPopMatrix();

}

void tree2()
{
   /**....................................... Big Tree (Right) ..........................................**/

    /**....................................... Big Tree (Right) Stem ..........................................**/

    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.73f, 0.19f);
    glVertex2f(0.744f, 0.472f);
    glVertex2f(0.754f, 0.472f);
    glVertex2f(0.764f, 0.19f);

    glVertex2f(0.738f, 0.255f);
    glVertex2f(0.736f, 0.274f);
    glVertex2f(0.684f, 0.303f);
    glVertex2f(0.680f, 0.298f);

    glVertex2f(0.759f, 0.303f);
    glVertex2f(0.759f, 0.319f);
    glVertex2f(0.815f, 0.350f);
    glVertex2f(0.824f, 0.347f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.744f, 0.408f);
    glVertex2f(0.687f, 0.460f);
    glVertex2f(0.744f, 0.424f);

    glVertex2f(0.755f, 0.421f);
    glVertex2f(0.815f, 0.493f);
    glVertex2f(0.755f, 0.439f);
    glEnd();




        /**....................................... Big Tree (Left) ..........................................**/



    /**....................................... Big Tree (Left) Stem ..........................................**/

    glPushMatrix();
    glTranslated(-1.7f,-0.02f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.73f, 0.19f);
    glVertex2f(0.744f, 0.472f);
    glVertex2f(0.754f, 0.472f);
    glVertex2f(0.764f, 0.19f);

    glVertex2f(0.738f, 0.255f);
    glVertex2f(0.736f, 0.274f);
    glVertex2f(0.684f, 0.303f);
    glVertex2f(0.680f, 0.298f);

    glVertex2f(0.759f, 0.303f);
    glVertex2f(0.759f, 0.319f);
    glVertex2f(0.815f, 0.350f);
    glVertex2f(0.824f, 0.347f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.744f, 0.408f);
    glVertex2f(0.687f, 0.460f);
    glVertex2f(0.744f, 0.424f);

    glVertex2f(0.755f, 0.421f);
    glVertex2f(0.815f, 0.493f);
    glVertex2f(0.755f, 0.439f);
    glEnd();
    glPopMatrix();



}

void tree_leaf1()
{
    /**....................................... Big Tree (Right) Top Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644,0.532,0.06);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644,0.477,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.691,0.568,0.07);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.771,0.563,0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.814,0.562,0.045);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.543,0.05);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.839,0.508,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.749,0.457,0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.796,0.485,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.709,0.442,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.695,0.457,0.055);

    /**....................................... Big Tree (Right) Right Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881,0.408,0.03);


    /**....................................... Big Tree (Right) Left Leaf ..........................................**/

    glPushMatrix();
    glTranslated(-0.18f,-0.055f,0.0f);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881,0.408,0.03);
    glPopMatrix();


}


void tree_leaf2()
{
    /**....................................... Big Tree (Left) Top Leaf ..........................................**/
    glPushMatrix();
    glTranslated(-1.7f,-0.02f,0.0f);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644,0.532,0.06);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644,0.477,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.691,0.568,0.07);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.771,0.563,0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.814,0.562,0.045);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.543,0.05);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.839,0.508,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.749,0.457,0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.796,0.485,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.709,0.442,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.695,0.457,0.055);

     /**....................................... Big Tree (Left) Right Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881,0.408,0.03);


    /**....................................... Big Tree (Left) Left Leaf ..........................................**/

    glPushMatrix();
    glTranslated(-0.18f,-0.055f,0.0f);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881,0.408,0.03);

    glPopMatrix();


    glPopMatrix();

}

void train1()
{
    /**....................................... Train ..........................................**/
    /**....................................... Train 1 ..........................................**/
        glPushMatrix();
        glTranslatef(position_train1x, 0.0f, 0.0f);
    ///Wheel of the train(Right Side);
       GLfloat x=0.12f;GLfloat  y=0.14f;GLfloat  radius =.022f;
       int triangleAmount = 100; ///# of lines used to draw circle
        GLfloat twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();
        ///Wheel of the train(Left Side);
       x=-0.01f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();
    /**....................................... Train 1 Cabin ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.098f, 0.2f, 0.0f);  // Dark olive green
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();
     ///Cabin(Front);
    glBegin(GL_QUADS);
    glColor3f(0.114f, 0.251f, 0.141f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();
    ///Left Window(Cabin);
     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();



    ///Right Window(Cabin);
     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();


    /// Yellow Safety Line (Extended to full width)
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.5, 0.5);
    glVertex2f(-0.05f, 0.24f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.24f);
    glVertex2f(-0.05f, 0.16f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.16f);

    glEnd();


    glPushMatrix();
    glTranslated(-0.24f,0.0f,0.0f);
      x=0.12f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();
        ///Wheel of the train(Left Side);
       x=-0.01f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();
     glBegin(GL_POLYGON);
    glColor3f(0.098f, 0.2f, 0.0f);  // Dark olive green
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.114f, 0.251f, 0.141f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();
    ///Left Window(Cabin);
     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();



    ///Right Window(Cabin);
     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

     /// Yellow Safety Line (Extended to full width)
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.5, 0.5);
    glVertex2f(-0.05f, 0.24f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.24f);
    glVertex2f(-0.05f, 0.16f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.16f);

    glEnd();

    glTranslated(-0.24f,0.0f,0.0f);
      x=0.12f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();
        ///Wheel of the train(Left Side);
       x=-0.01f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.098f, 0.2f, 0.0f);  // Dark olive green
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.114f, 0.251f, 0.141f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();
    ///Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();



    ///Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();
      /// Yellow Safety Line (Extended to full width)
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.5, 0.5);
    glVertex2f(-0.05f, 0.24f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.24f);
    glVertex2f(-0.05f, 0.16f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.16f);

    glEnd();



        glPopMatrix();
    /**....................................... Train 1 Engine ..........................................**/

        ///First wheel of left side;
        x=0.22f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        ///Seocond wheel of Left side;
         x=0.27f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
        twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        ///First wheel of Right side;
         x=0.45f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();
        ///Second wheel of Right side;
         x=0.415f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.118f, 0.227f, 0.333f);
    glVertex2f(0.19f, 0.14f);
    glVertex2f(0.19f, 0.25f);
    glVertex2f(0.22f, 0.28f);
    glVertex2f(0.27f, 0.28f);
    glVertex2f(0.27f, 0.27f);
    glVertex2f(0.50f, 0.27f);
    glVertex2f(0.50f, 0.17f);
    glVertex2f(0.48f, 0.15f);
    glVertex2f(0.25f, 0.15f);
    glVertex2f(0.24f, 0.14f);
    glVertex2f(0.17f, 0.14f);
    glEnd();

     ///Back of the engine(Front);
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);  // Gray
    glVertex2f(0.24f, 0.14f);
    glVertex2f(0.24f, 0.25f);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.25f, 0.15f);
    glEnd();

     ///Back of the engine(Front_Upper);
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);  // Gray
    glVertex2f(0.24f, 0.25f);
    glVertex2f(0.27f, 0.28f);
    glVertex2f(0.27f, 0.27f);
    glVertex2f(0.25f, 0.25f);
    glEnd();

    ///Front of the engine(Front);
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f);  // Gray
    glVertex2f(0.48f, 0.15f);
    glVertex2f(0.48f, 0.25f);
    glVertex2f(0.50f, 0.27f);
    glVertex2f(0.50f, 0.17f);
    glEnd();

    ///Front of the engine(Back_Step);
    glBegin(GL_QUADS);
    glColor3f(0.82f, 0.816f, 0.451f);
    glVertex2f(0.19f, 0.20f);
    glVertex2f(0.19f, 0.23f);
    glVertex2f(0.24f, 0.23f);
    glVertex2f(0.24f, 0.20f);
    glEnd();

    ///Front of the engine(Stape);
    glBegin(GL_QUADS);
    glColor3f(0.722f, 0.714f, 0.322f);
    glVertex2f(0.24f, 0.20f);
    glVertex2f(0.24f, 0.23f);
    glVertex2f(0.25f, 0.24f);
    glVertex2f(0.25f, 0.21f);
    glEnd();

    ///Front of the engine(Stape);
    glBegin(GL_QUADS);
    glColor3f(0.82f, 0.816f, 0.451f);
    glVertex2f(0.25f, 0.21f);
    glVertex2f(0.25f, 0.24f);
    glVertex2f(0.48f, 0.24f);
    glVertex2f(0.48f, 0.21f);
    glEnd();

     ///Front of the engine(Stape_Front);
    glBegin(GL_QUADS);
    glColor3f(0.722f, 0.714f, 0.322f);
    glVertex2f(0.48f, 0.21f);
    glVertex2f(0.48f, 0.24f);
    glVertex2f(0.50f, 0.25f);
    glVertex2f(0.50f, 0.23f);
    glEnd();

    ///Front of the engine(Side Black Side);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.24f, 0.14f);
    glVertex2f(0.25f, 0.15f);
    glVertex2f(0.48f, 0.15f);
    glVertex2f(0.47f, 0.14f);
    glEnd();

    ///Front of the engine(Side Black Side(Upper));
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glVertex2f(0.46f, 0.24f);
    glVertex2f(0.46f, 0.19f);
    glEnd();

     ///Back of the Engine(Window)......................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.195f, 0.18f);
    glVertex2f(0.195f, 0.22f);
    glVertex2f(0.235f, 0.22f);
    glVertex2f(0.235f, 0.18f);
    glEnd();


     ///Front of the engine(Side Black Side(White line));
     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glPushMatrix();
    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();




    glPopMatrix();
    glPopMatrix();
    /// End Of the train-1 ..................................................................


}

void train2()
{
      /**....................................... Train 2 ..........................................**/
    glPushMatrix();
      glTranslatef(position_train2x, 0.0f, 0.0f);
    glPushMatrix();
    glTranslated(0.1f,-0.08f,0.0f);
     GLfloat x=0.12f; GLfloat y=0.14f;GLfloat  radius =.022f;
        int triangleAmount = 100; ///# of lines used to draw circle
         GLfloat twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();
        ///Wheel of the train(Left Side);

       x=-0.01f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.2f);  // Dark purple
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.5f, 0.4f);  // Deep dark peach
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();

    ///Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();




    ///Right Window(Cabin);
     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

     /// Yellow Safety Line (Extended to full width)
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.5, 0.5);
    glVertex2f(-0.05f, 0.24f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.24f);
    glVertex2f(-0.05f, 0.16f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.16f);

    glEnd();




    glTranslated(-0.24f,0.00f,0.0f);
      x=0.12f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        ///Wheel of the train(Left Side);
       x=-0.01f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.2f);  // Dark purple
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.6f, 0.5f, 0.4f);  // Deep dark peach
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();

    ///Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    ///Right Window(Cabin);
     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

     /// Yellow Safety Line (Extended to full width)
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.5, 0.5);
    glVertex2f(-0.05f, 0.24f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.24f);
    glVertex2f(-0.05f, 0.16f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.16f);

    glEnd();




    glEnd();
    glTranslated(-0.24f,0.00f,0.0f);
      x=0.12f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        ///Wheel of the train(Left Side);
       x=-0.01f;  y=0.14f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.2f);  // Dark purple
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.5f, 0.4f);  // Deep dark peach
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();

    ///Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

 /// Yellow Safety Line (Extended to full width)
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.5, 0.5);
    glVertex2f(-0.05f, 0.24f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.24f);
    glVertex2f(-0.05f, 0.16f);  // Start point of the line (left side of the cabin)
    glVertex2f(0.16f, 0.16f);

    glEnd();

    ///Right Window(Cabin);
     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();
    glPopMatrix();



     /**....................................... Train 2 Engine ..........................................**/

     ///Wheel of the 2nd engine(1st right side)
       x=-0.49f;  y=0.06f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        ///Wheel of the 2nd engine(2nd right side)
       x=-0.53f;  y=0.06f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

    ///Wheel of the 2nd engine(1st left side)
       x=-0.66f;  y=0.06f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        ///Wheel of the 2nd engine(1st left side)
       x=-0.70f;  y=0.06f;  radius =.022f;
        triangleAmount = 100; ///# of lines used to draw circle
         twicePi =2.0f * PI;
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); /// center of circle
        for(float i = 1.0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

         ///Polygon of second engine.............................................
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.2f, 0.2f);  // Dark teal color
    glVertex2f(-0.46f, 0.06f);
    glVertex2f(-0.46f, 0.17f);
    glVertex2f(-0.43f, 0.20f);
    glVertex2f(-0.50f, 0.20f);
    glVertex2f(-0.51f, 0.19f);
    glVertex2f(-0.70f, 0.19f);
    glVertex2f(-0.73f, 0.16f);
    glVertex2f(-0.73f, 0.07f);
    glVertex2f(-0.54f, 0.07f);
    glVertex2f(-0.53f, 0.06f);
    glVertex2f(-0.46f, 0.06f);
    glEnd();

    ///Back Of The Engine.......................................................
    glBegin(GL_QUADS);
    glColor3f(0.663f, 0.235f, 0.141f);
    glVertex2f(-0.46f, 0.06f);
    glVertex2f(-0.46f, 0.17f);
    glVertex2f(-0.43f, 0.20f);
    glVertex2f(-0.43f, 0.10f);
    glEnd();

    ///Upper Rooftoof of the Engine...............................................
      glBegin(GL_QUADS);
glColor3f(0.0f, 0.2f, 0.2f);  // Dark teal color
    glVertex2f(-0.73f, 0.16f);
    glVertex2f(-0.70f, 0.19f);
    glVertex2f(-0.51f, 0.19f);
    glVertex2f(-0.54f, 0.16f);
    glEnd();

    ///2nd Train left side design...........................................
    glBegin(GL_QUADS);
    glColor3f(0.663f, 0.235f, 0.141f);
    glVertex2f(-0.55f, 0.07f);
    glVertex2f(-0.55f, 0.16f);
    glVertex2f(-0.53f, 0.17f);
    glVertex2f(-0.53f, 0.06f);
    glEnd();



     ///2nd Train engine front of the black...........................................
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.72f, 0.06f);
    glVertex2f(-0.73f, 0.07f);
    glVertex2f(-0.54f, 0.07f);
    glVertex2f(-0.53f, 0.06f);
    glEnd();

    ///Front engine yellow design........................................................
    glBegin(GL_QUADS);
    glColor3f(0.769f, 0.702f, 0.576f);
    glVertex2f(-0.73f, 0.12f);
    glVertex2f(-0.73f, 0.15f);
    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.55f, 0.12f);
    glEnd();

     ///Front engine yellow design(Back side)........................................................
    glBegin(GL_QUADS);
    glColor3f(0.741f, 0.62f, 0.51f);
    glVertex2f(-0.55f, 0.12f);
    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.53f, 0.14f);
    glVertex2f(-0.53f, 0.11f);
    glEnd();

    ///Back engine yellow design(Back Left side)................................
    glBegin(GL_QUADS);
    glColor3f(0.769f, 0.702f, 0.576f);
    glVertex2f(-0.53f, 0.11f);
    glVertex2f(-0.53f, 0.14f);
    glVertex2f(-0.46f, 0.14f);
    glVertex2f(-0.46f, 0.11f);
    glEnd();

     ///Back of the engine yellow design(Back side)........................................................
    glBegin(GL_QUADS);
    glColor3f(0.741f, 0.62f, 0.51f);
    glVertex2f(-0.46f, 0.11f);
    glVertex2f(-0.46f, 0.14f);
    glVertex2f(-0.43f, 0.16f);
    glVertex2f(-0.43f, 0.13f);
    glEnd();

     ///Back of the Engine(Window)......................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.52f, 0.10f);
    glVertex2f(-0.52f, 0.14f);
    glVertex2f(-0.48f, 0.14f);
    glVertex2f(-0.48f, 0.10f);
    glEnd();


     ///Front of the engine side black design........................................................
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glVertex2f(-0.64f, 0.15f);
    glVertex2f(-0.64f, 0.10f);
    glEnd();

    ///Front of the engine side black design(Outside Line)........................................................
    glLineWidth(0.8);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void kashPhulStructure()
{
    glPushMatrix();
    glTranslatef(0.0f,0.0f,0.0f);
    /// KashPhul Stems
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.950f, 0.125f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.775f, 0.0f);
    glVertex2f(0.850f, 0.175f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.85f, 0.0f);
    glVertex2f(0.750f, 0.175f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.65f, 0.0f);
    glVertex2f(0.625f, 0.150f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.725f, 0.0f);
    glVertex2f(0.675f, 0.125f);
    glEnd();

    /// KashPhuls
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.950f, 0.125f);
    glVertex2f(0.975f, 0.150f);
    glVertex2f(0.975f, 0.250f);
    glVertex2f(0.925f, 0.175f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.85f, 0.175f);
    glVertex2f(0.9f, 0.250f);
    glVertex2f(0.9f, 0.3f);
    glVertex2f(0.85f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.75f, 0.175f);
    glVertex2f(0.750f, 0.2f);
    glVertex2f(0.7f, 0.250f);
    glVertex2f(0.725f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.625f, 0.15f);
    glVertex2f(0.625f, 0.150f);
    glVertex2f(0.625f, 0.250f);
    glVertex2f(0.6f, 0.175f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.675f, 0.125f);
    glVertex2f(0.675f, 0.150f);
    glVertex2f(0.65f, 0.175f);
    glVertex2f(0.65f, 0.150f);
    glEnd();

    /// Green Bushes
    GLfloat x=0.9f;  GLfloat y=0.0f;  GLfloat radius =.1f;
    int triangleAmount = 100; ///# of lines used to draw circle
    GLfloat twicePi =2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

     x=0.7f;   y=0.0f;   radius =.15f;
     triangleAmount = 100; ///# of lines used to draw circle
     twicePi =2.0f * PI;
    glColor3f(0.161, 0.541, 0.137);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    /// Kashphul In front of the bush
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.675f, 0.125f);
    glVertex2f(0.675f, 0.150f);
    glVertex2f(0.65f, 0.175f);
    glVertex2f(0.65f, 0.150f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.725f, 0.0f);
    glVertex2f(0.675f, 0.125f);
    glEnd();



     x=0.6f;   y=0.0f;   radius =.07f;
     triangleAmount = 100; ///# of lines used to draw circle
     twicePi =2.0f * PI;
    glColor3f(0.373, 0.69, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.7f;   y=0.003f;   radius =.05f;
     triangleAmount = 100; ///# of lines used to draw circle
     twicePi =2.0f * PI;
    glColor3f(0.373, 0.6, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    /// Leaves
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.9f, 0.0f);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.85f, 0.125f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.925f, 0.0f);
    glVertex2f(0.95f, 0.0f);
    glVertex2f(1.0f, 0.125f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.775f, 0.0f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.7f, 0.150f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.825f, 0.0f);
    glVertex2f(0.825f, 0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.650f, 0.075f);
    glVertex2f(0.725f, 0.0f);
    glVertex2f(0.75f, 0.125f);
    glVertex2f(0.750f, 0.0f);
    glEnd();
    /// Bush In front of the KashPhul
     x=0.8f;   y=0.001f;   radius =.05f;
     triangleAmount = 100; ///# of lines used to draw circle
     twicePi =2.0f * PI;
    glColor3f(0.373, 0.62, 0.349);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount;i++) {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.722, 0.082);
    glVertex2f(0.650f, 0.0f);
    glVertex2f(0.675f, 0.0f);
    glVertex2f(0.55f, 0.125f);
    glEnd();
    glPopMatrix();
}void kashPhul()
{
    glPushMatrix();
    glScalef(0.4f,0.4f,0.0f);
    glTranslatef(0.5f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(0.5f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(0.5f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(0.5f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.3f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.3f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.3f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.3f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f,-0.002f,0.0f);
    kashPhulStructure();
    glTranslatef(-0.4f,-0.002f,0.0f);
    kashPhulStructure();
    glPopMatrix();
    }



void station_grass1()
{
    /**....................................... Grass ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.271, 0.463, 0.043);
    glVertex2f(-1.0f, 0.0f);
    glColor3f(0.643, 0.753, 0.227);
    glVertex2f(-1.0f, -1.0f);
    glColor3f(0.271, 0.463, 0.043);
    glVertex2f(1.0f, -1.0f);
    glColor3f(0.643, 0.753, 0.227);
    glVertex2f(1.0f, 0.0f);
    glEnd();

}
void station_grass()
{
    /**....................................... Grass ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.271, 0.463, 0.043);
    glVertex2f(-1.0f, 0.22f);
    glColor3f(0.643, 0.753, 0.227);
    glVertex2f(-1.0f, 0.55f);
    glColor3f(0.643, 0.753, 0.227);
    glVertex2f(1.0f, 0.3f);
    glColor3f(0.271, 0.463, 0.043);
    glVertex2f(1.0f, 0.22f);
    glEnd();



/**....................................... Grass between second and third rail tracks ..........................................**/

    // Grass between the second rail track (-y direction) and third rail track (-y direction)
    glBegin(GL_QUADS);
    glColor3f(0.271, 0.463, 0.043); // Dark green for bottom part of grass
    glVertex2f(-1.0f, -0.6f);      // Bottom-left of the grass area (aligned with third rail track)
    glVertex2f(-1.0f, -0.3f);      // Bottom-left of the grass section (aligned with second rail track)
    glColor3f(0.643, 0.753, 0.227); // Lighter green for top part of grass
    glVertex2f(1.0f, -0.3f);       // Bottom-right of the grass section (aligned with second rail track)
    glVertex2f(1.0f, -0.6f);       // Bottom-right of the grass area (aligned with third rail track)
    glEnd();

    // Add Kash Phul within the grass area (between second and third rail tracks)
    glPushMatrix();
    glTranslatef(0.0f, -0.45f, 0.0f); // Positioning the Kash Phul structures within the grass area
    kashPhul(); // Drawing the Kash Phul structures multiple times
    glPopMatrix();
}





void road2()
{
    /**....................................... Station Road ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.301, 0.33, 0.35);
    glVertex2f(0.43f, 0.39f);

    glVertex2f(0.64f, 0.39f);

    glVertex2f(0.0f, 0.22f);
    glVertex2f(-0.1f, 0.22f);
    glEnd();
    /**....................................... Side Divider  ..........................................**/
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-0.1f, 0.22f);
    glVertex2f(0.42f, 0.383f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(0.0f, 0.22f);
    glVertex2f(0.51f, 0.36f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(0.37f, 0.345f);
    glVertex2f(0.44f, 0.365f);
    glEnd();
}


void display() {
    // Set background color to dark blue for night sky
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
     glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    sky();
    cloud1();
    cloud2();
    cloud3();
    sun();
    sea();
    boat1();
    boat2();
    beach();
    road();
    car();
    bus1();
    bus2();
    station_grass1();
    kashPhul();
    station_grass();
    road2();
    hills();
    station();
    tree1();
    tree2();
     tree_leaf1();
    tree_leaf2();
    platform();


    rail_Line();
    rail_Line1();
    train1();
    train2();
        glutSwapBuffers();

    glFlush();
}


///.................................................Frame3........................................................///



float move_boat_third=0.0f;
float move_car_second=0.0f;
float move_clouds= 0.0f;
float move_car=0.0f;
float move_truck=0.0f;
float move_bird_x=0.0f;
float move_bird_y=0.0f;
float move_train=0.0f;
float move_boat=0.0f;
float move_boat_second=0.0f;
float move_wave=0.0f;
float count=0;
bool main_page=false;
bool bird_position_status=false;
int perDisplayTime=15000;
int totalScreenTime=0;
int currentScenario=1;


/*void sound()
{

        sndPlaySound("secondbird.wav",SND_FILENAME|SND_SYNC|SND_LOOP);



}*/
void init()
{
   glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,80);
    glMatrixMode(GL_MODELVIEW);
}
void update_boat_third(int value)
{
    move_boat_third=move_boat_third-0.1;
    if(move_boat_third<-100)
    {
        move_boat_third=0;
    }
    glutPostRedisplay();
    glutTimerFunc(60,update_boat_third,0);
}
void update_car_second(int value)
{
    move_car_second=move_car_second+0.1;
    if(move_car_second>100)
    {
        move_car_second=0;
    }
      glutPostRedisplay();
    glutTimerFunc(20,update_car_second,0);
}
void update_wave(int value)
{
    move_wave=move_wave+0.1;

    if(move_wave>100)
    {
        move_wave=-10;

    }
    glutPostRedisplay();
glutTimerFunc(50,update_wave,0);
}
void update_boat(int value)
{
     move_boat=move_boat+0.15;

    if(move_boat>100)
    {
        move_boat=-5;

    }
    glutPostRedisplay();
glutTimerFunc(50,update_boat,0);

}
void update_boat_two(int value)
{
     move_boat_second=move_boat_second+0.1;

    if(move_boat_second>100)
    {
        move_boat_second=-5;

    }
    glutPostRedisplay();
glutTimerFunc(50,update_boat_two,0);

}
void update_train(int value)
{
    move_train=move_train-0.2;
    if(move_train<-100)
    {
        move_train=120;
    }
    glutPostRedisplay();
glutTimerFunc(20,update_train,0);
}
void update_cloud(int value)
{
move_clouds+= 0.12;
    if(move_clouds >100)
    {
    move_clouds =-42;
    }
glutPostRedisplay();
glutTimerFunc(30, update_cloud, 0);
}

void update_car(int value)     ///car_right to left _move
{
    move_car-=0.15;
    if(move_car<-100)
    {
    move_car =5;
    }
    glutPostRedisplay();
glutTimerFunc(20,update_car,0);
}
void update_truck(int value)
{
    move_truck=move_truck+0.1;
    if(move_truck>100)
    {
        move_truck=-5;
    }
    glutPostRedisplay();
glutTimerFunc(20,update_truck,0);
}
void update_bird(int value)
{
    if(bird_position_status==false)
    {
    move_bird_x=move_bird_x+0.9;
    move_bird_y=move_bird_y-1;
    bird_position_status=true;
    }
    else{
            move_bird_x=move_bird_x+0.9;
            move_bird_y=move_bird_y+1;
        bird_position_status=false;
    }

    if(move_bird_x>100)
    {
        move_bird_x=-10;
        move_bird_y=0;
    }
    glutPostRedisplay();
glutTimerFunc(200,update_bird,0);
}
void circle2(float x, float y, float radius)
{

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();
}

void wheel_for_train(float x,float y,float radius)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(23, 32, 42);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();

}

void grass(float x,float y,float radius)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(7, 126, 8);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();

}

void wheel(float x,float y,float radius)//truck er jonno
{
     glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(252, 249, 252);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();
}

void circle_for_flower(float x,float y,float radius)
{
      glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(231, 76, 60);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();

}
void circle_for_flower_two(float x,float y,float radius)
{
      glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(213, 223, 13);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();

}
void circle_for_flower_middle(float x,float y,float radius)
{
      glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(247, 220, 111);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();

}

void mountain()
{

//171, 235, 198
    //background mountain drawing
    glColor3ub(163, 235, 131);
    glBegin(GL_POLYGON);
    glVertex2f(20,55);
    glVertex2f(34,67);
    glVertex2f(36,67);
    glVertex2f(38,68);
    glVertex2f(40,68);
    glVertex2f(41,67);
    glVertex2f(43,67);
    glVertex2f(45,68);
    glVertex2f(46,68);
    glVertex2f(60,55);
    glVertex2f(20,55);

    glEnd();

    //front
    //prothom pahar
    glColor3ub(9, 105, 5);
    glBegin(GL_POLYGON);
    glVertex2f(0,55);
    glVertex2f(30,55);
    glVertex2f(15,71);
    glVertex2f(0,55);
    //glEnd();

    //prothom pahar e ektu 3d shape

    glColor3ub(206, 235, 163);
    glBegin(GL_POLYGON);
    glVertex2f(5,60);
    glVertex2f(6,60);
    glVertex2f(8,61);
    glVertex2f(15,71);
    glVertex2f(5,60);
    glEnd();
    //first pahar e arektu 3d shape


    glColor3ub(168, 235, 139);
    glBegin(GL_POLYGON);
    glVertex2f(15,71);
    glVertex2f(16,69.5);
    glVertex2f(17,69);
    glVertex2f(18,68.2);
    glVertex2f(19,67);
    glVertex2f(20,66.5);
    glVertex2f(21.6,66);
    glVertex2f(20,65);
    glVertex2f(15,71);

    glEnd();


  //front mountain drawing
     glColor3ub(110, 151, 93);
    glBegin(GL_POLYGON);
    glVertex2f(0,63);
    glVertex2f(1,64);
    glVertex2f(3,64);
    glVertex2f(6,67);
    glVertex2f(9,64);
    glVertex2f(8,62);
    glVertex2f(5,65);
    glVertex2f(0,60);
    glVertex2f(0,63);
   // glEnd();

     glColor3ub(59, 187, 4);
    glBegin(GL_POLYGON);
    glVertex2f(0,60);
    glVertex2f(5,65);
    glVertex2f(8,62);
    glVertex2f(0,55);
    glVertex2f(0,60);
    glEnd();

     //second pahar
     glColor3ub(9, 105, 5);
    glBegin(GL_POLYGON);
    glVertex2f(20,65);
    glVertex2f(23,69);
    glVertex2f(24,69);
    glVertex2f(37,55);
    glVertex2f(30,55);
    glVertex2f(20,65);
   // glEnd();
   //second pahar a 3d shape
    glColor3ub(152, 225, 120);
    glBegin(GL_POLYGON);
    glVertex2f(20,65);
    glVertex2f(21,64);
    glVertex2f(21.5,65);
    glVertex2f(22.5,67);
    glVertex2f(23,68);
    glVertex2f(23,69);
    glVertex2f(20,65);
    glEnd();
    //third pahar
   glColor3ub(9, 105, 5);
    glBegin(GL_POLYGON);
    glVertex2f(30,55);
    glVertex2f(50,67);
    glVertex2f(52,67);
    glVertex2f(70,55);
    glVertex2f(30,55);
    //third pahar er 3d shape

     glColor3ub(168, 235, 139);
    glBegin(GL_POLYGON);
    glVertex2f(52,67);
    glVertex2f(56,66);
    glVertex2f(59,64.5);
    glVertex2f(60,63.5);
    glVertex2f(62,62);
    glVertex2f(65,60);
    glVertex2f(67,58);
    glVertex2f(68,58);
    glVertex2f(71,55);
    glVertex2f(70,55);
    glVertex2f(52,67);

    glEnd();


}
void day()
{
     //glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glLoadIdentity();
    glColor3f(0.4f,0.69f,1.0f);
    //SKY AND MOUNTAIN PORTION AND SUN
    glBegin(GL_POLYGON);

    glVertex2f(0,55);
    glVertex2f(100,55);
    glVertex2f(100,80);
    glVertex2f(0,80);
    glEnd();

    //SUN
      glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(250, 229, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=5.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+50,y+73);
        }
  glEnd();

  //MOUNTAINS
  glPushMatrix();
   mountain();
  glPopMatrix();
   //Mountain er nicher part......
   glColor3ub(100, 97, 11);
   glBegin(GL_POLYGON);
   glVertex2f(0,50);
   glVertex2f(100,50);
   glVertex2f(100,55);
   glVertex2f(0,55);
   glVertex2f(0,50);

   glEnd();
   glLoadIdentity();
   //houses....
   glPushMatrix();
   glColor3ub(234, 233, 131);
   glBegin(GL_POLYGON);
   glVertex2f(80,55);
   glVertex2f(84,55);
   glVertex2f(84,58);
   glVertex2f(80,58);
   glVertex2f(80,55);


   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(84,55);
   glVertex2f(84,58);
   glEnd();

glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(80,55);
   glVertex2f(80,58);
   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(80,58);
   glVertex2f(84,58);
   glEnd();

   glColor3ub(190, 189, 139);
   glBegin(GL_POLYGON);
   glVertex2f(84,55);
   glVertex2f(89,55);
   glVertex2f(89,58);
   glVertex2f(84,58);
   glVertex2f(84,55);

   glEnd();

   glColor3ub(242, 145, 13);
   glBegin(GL_POLYGON);
   glVertex2f(80,58);
   glVertex2f(84,58);
   glVertex2f(82,60);
   glVertex2f(80,58);


   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(82,60);
   glVertex2f(84,58);
   glEnd();


    glColor3ub(177, 108, 14);
   glBegin(GL_POLYGON);
   glVertex2f(82,60);
   glVertex2f(84,58);
   glVertex2f(89,58);
   glVertex2f(87,60);
    glVertex2f(82,60);


   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(84,58);
   glVertex2f(89,58);
   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(87,60);
   glVertex2f(89,58);
   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(82,60);
   glVertex2f(87,60);
   glEnd();


   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(89,55);
   glVertex2f(89,58);
   glEnd();

    glColor3ub(111, 111, 105);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2f(82,60);
   glVertex2f(80,58);
   glEnd();

    glColor3ub(177, 108, 14);
   glBegin(GL_POLYGON);
   glVertex2f(86,55);
   glVertex2f(87,55);
   glVertex2f(87,57);
   glVertex2f(86,57);
    glVertex2f(86,55);


   glEnd();

    glColor3ub(177, 108, 14);
   glBegin(GL_POLYGON);
   glVertex2f(81.5,56);
   glVertex2f(82.5,56);
   glVertex2f(82.5,57);
   glVertex2f(81.5,57);
    glVertex2f(81.5,56);


   glEnd();





   glPopMatrix();


   //crop yeild one
   glTranslatef(+0.0f,0.0f,0.0f);
   glPushMatrix();
   glColor3ub(191, 189, 115);
   glBegin(GL_POLYGON);
   glVertex2f(15,51);
   glVertex2f(22,51);
   glVertex2f(24,54);
   glVertex2f(18,54);
   glVertex2f(15,51);
   glEnd();
   //dhaan
    glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();
   glLoadIdentity();
   glTranslatef(-0.5f,-1.0f,0.0f);
   //second raw dhaan er
   glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();


   glPopMatrix();
    //glLoadIdentity();
    // crop yield field second number
    glTranslatef(+8.0f,0.0f,0.0f);
    glPushMatrix();
   glColor3ub(191, 189, 115);
   glBegin(GL_POLYGON);
   glVertex2f(15,51);
   glVertex2f(22,51);
   glVertex2f(24,54);
   glVertex2f(18,54);
   glVertex2f(15,51);
   glEnd();
   //dhaan
    glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();
   //glLoadIdentity();
   glTranslatef(-0.5f,-1.0f,0.0f);
   //second raw dhaan er
   glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();


   glPopMatrix();
   glLoadIdentity();
   //crop field third number...
   glTranslatef(+8.0f,0.0f,0.0f);

    glTranslatef(+8.0f,0.0f,0.0f);
    glPushMatrix();
   glColor3ub(191, 189, 115);
   glBegin(GL_POLYGON);
   glVertex2f(15,51);
   glVertex2f(22,51);
   glVertex2f(24,54);
   glVertex2f(18,54);
   glVertex2f(15,51);
   glEnd();
   //dhaan
    glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();
   //glLoadIdentity();
   glTranslatef(-0.5f,-1.0f,0.0f);
   //second raw dhaan er
   glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();


   glPopMatrix();
   glLoadIdentity();
    //TREES........








    glPushMatrix();
    //back boro boro trees......

    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

    glTranslatef(2.5f,0.0f,0.0f);

    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

    glTranslatef(2.5f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
    glTranslatef(4.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
     glTranslatef(4.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(4.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();


     glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();

    glPopMatrix();


     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
     glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();


     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
 glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
    glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
 glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();











    //finished tree back.......




     glLoadIdentity();
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslatef(1.0f,0.0f,0.0f);


    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();

    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();

    glPopMatrix();


    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();

   glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();



    glPopMatrix();





  //CLOUDS
   glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_clouds, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
        glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+5,y+70);
        }

  glEnd();
   glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {

        glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+7,y+72);
        }
  glEnd();
  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
      glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+9,y+70);
        }
  glEnd();
  glPopMatrix();
  //CLOUD 2

 // glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_clouds, 0.0f, 0.0f);

  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
        glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+20,y+68);
        }
  glEnd();

  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
       glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+25,y+68);
        }
  glEnd();

  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
        glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+23,y+71);
        }
  glEnd();
  glLoadIdentity();
  glPopMatrix();
  glTranslatef(move_clouds,0.0f,0.0f);
   //CLOUD 3
   glPushMatrix();
   circle2(43,70,3);
   circle2(40,70,3);
   circle2(41.5,72,3);
   circle2(44,71,3);
   circle2(38,71,3);
   glPopMatrix();

   //BIRDS
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(move_bird_x,move_bird_y,0.0f);
   glColor3ub(22, 20, 22);
   glLineWidth(1.5);
   glBegin(GL_LINES);
    glVertex2f(2,70);
    glVertex2f(4,69);
    glVertex2f(4,69);
    glVertex2f(6,71);


   glEnd();

   glColor3ub(22, 20, 22);
   glLineWidth(1.5);
   glBegin(GL_LINES);
    glVertex2f(8,73);
    glVertex2f(10,71);
    glVertex2f(10,71);
    glVertex2f(12,74);

   glEnd();

   glColor3ub(22, 20, 22);
   glLineWidth(1.5);
   glBegin(GL_LINES);
    glVertex2f(11,70);
    glVertex2f(13,68);
    glVertex2f(13,68);
    glVertex2f(15,70);


   glEnd();


   glPopMatrix();




  //SEA AND BOATS

   glLoadIdentity();
   //river border....
   //124, 237, 245
   glColor3ub(124, 237, 245);
    glBegin(GL_POLYGON);

    glVertex2f(0,30);
    glVertex2f(100,30);
    glVertex2f(100,50);
    glVertex2f(0,50);
    glVertex2f(0,30);

    glEnd();
    glLoadIdentity();
    //panir sroooot......
    glPushMatrix();

     glTranslatef(move_wave,0.0f,0.0f);
    glColor3ub(212, 230, 241);
    glBegin(GL_POLYGON);
    glVertex2f(28,40);
    glVertex2f(37,39.5);
    glVertex2f(48,39.5);
    glVertex2f(51,40);
    glVertex2f(48,40.5);
    glVertex2f(37,40.5);
    glVertex2f(28,40);


    glEnd();


     glColor3ub(212, 230, 241);
    glBegin(GL_POLYGON);
    glVertex2f(60,45.5);
    glVertex2f(72,45.5);
    glVertex2f(80,45.5);
    glVertex2f(88,46);
    glVertex2f(60,46);
    glVertex2f(60,45.5);
    glVertex2f(60,45.5);


    glEnd();


     glColor3ub(212, 230, 241);
    glBegin(GL_POLYGON);
    glVertex2f(20,47.5);
    glVertex2f(40,47.5);
    glVertex2f(47,47);
    glVertex2f(52,48);
    glVertex2f(20,48);
    glVertex2f(20,47.5);



    glEnd();

    glPopMatrix();
    glLoadIdentity();
    //boats.....

    //boat one  moving.....
    glPushMatrix();

      glTranslatef(move_boat,0.0f,0.0f);
    glColor3ub(100, 68, 73);
    glBegin(GL_POLYGON);
    glVertex2f(10,47);
    glVertex2f(12,46);
    glVertex2f(14,46);
    glVertex2f(16,47);
    glVertex2f(10,47);
    glEnd();

    glColor3ub(168, 161, 162);
    glBegin(GL_POLYGON);
    glVertex2f(12,47);
    glVertex2f(14,47);
    glVertex2f(14,47.5);
    glVertex2f(12,47.5);
    glVertex2f(12,47);
    glEnd();



    glPopMatrix();
    glLoadIdentity();

    //boat two moving......
    glPushMatrix();
     glTranslatef(move_boat_second,0.0f,0.0f);
    glColor3ub(41, 38, 38);
    glBegin(GL_POLYGON);
    glVertex2f(3,42);
    glVertex2f(5,40);
    glVertex2f(10,40);
    glVertex2f(12,42);
    glVertex2f(3,42);
    glEnd();



    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(7,46);
    glVertex2f(10,43);
    glVertex2f(7,42);
    glVertex2f(7,46);

    glEnd();

    glColor3ub(20, 20, 19);
    glLineWidth(1.5);
    glBegin(GL_LINES);

    glVertex2f(7,42);
    glVertex2f(7,46);


    glEnd();


    glPopMatrix();

      glLoadIdentity();

    //ROAD AND CARS
    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex2f(0,10);
    glVertex2f(100,10);
    glVertex2f(100,30);
    glVertex2f(0,30);
    glVertex2f(0,0);
    glEnd();


     glLoadIdentity();
    glPushMatrix();
    glTranslatef(+0.0f,0.0f,0.0f);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();
    glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();


    glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();


     glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();

     glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();
    glPopMatrix();

    //MOVING CAR ONE
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_car,0.0f, 0.0f);
    glColor3f(0.1373, 0.5725,0.5529);
    glBegin(GL_QUADS);
    glVertex2f(85,23.5);
    glVertex2f(94,23.5);
    glVertex2f(94,25);
    glVertex2f(85,25);
    glVertex2f(85,23.5);
    glEnd();

    glColor3ub(170, 183, 184);
    glBegin(GL_POLYGON);
    glVertex2f(86.5,25);//glVertex2f(5,38)
                        //glVertex2f(14,38)
                        //.....(14,42)
                        //(5,40)
                        //(5,38)
    glVertex2f(88,26.5);
    glVertex2f(92,26.5);
    glVertex2f(93,25);
    glVertex2f(86.5,25);
    glEnd();


     glColor3ub(23, 32, 42);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(86.5,25);
    glVertex2f(88,26.5);
    glVertex2f(88,26.5);
    glVertex2f(88,25);
    glVertex2f(88,25);
     glVertex2f(86.5,25);
    glEnd();

     glColor3ub(23, 32, 42);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(92,25);
    glVertex2f(92,26.5);
    glVertex2f(92,26.5);
    glVertex2f(93,25);
    glVertex2f(93,25);
    glVertex2f(92,25);

    glEnd();
  //wheel 1
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(213, 216, 220);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+87,y+23.5);
        }
  glEnd();

     //wheel 2
      glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(213, 216, 220);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+93,y+23.5);
        }
  glEnd();


    glPopMatrix();


    //MOVING TRUCK
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_truck,0.0f,0.0f);
    glColor3ub(222, 13, 187);
    glBegin(GL_POLYGON);
    glVertex2f(5,14);
    glVertex2f(15,14);
    glVertex2f(15,18);
    glVertex2f(5,18);
    glVertex2f(5,14);

    glEnd();

     glColor3ub(91, 86, 90);
    glBegin(GL_POLYGON);
    glVertex2f(15,14);
    glVertex2f(17,14);
    glVertex2f(17,16);
    glVertex2f(15,17);
    glVertex2f(15,14);

    glEnd();

    glColor3ub(234, 228, 233);
    glBegin(GL_POLYGON);

    glVertex2f(15,16);
    glVertex2f(17,16);
    glVertex2f(15,17);
    glVertex2f(15,16);

    glEnd();

    wheel(6.5,14,0.8);
    wheel(14,14,0.8);


    glPopMatrix();
    glLoadIdentity();
     //NICHER ROAD BORDER......
     glPushMatrix();
    glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(0,13);
    glVertex2f(100,13);
    glVertex2f(100,14);
    glVertex2f(0,14);
    glVertex2f(0,13);

    glEnd();
     glTranslatef(+0.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();

     glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();

    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();



    glPopMatrix();
    glLoadIdentity();

    //TRAIN
    //train er ekdom niche...
    glColor3ub(97, 84, 4);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,0);
    glVertex2f(100,2.5);
    glVertex2f(0,2.5);
    glVertex2f(0,0);

    glEnd();
    //TRAIN LINE  BORDER......
     glColor3ub(204, 209, 209);
    glBegin(GL_POLYGON);
    glVertex2f(0,2.5);
    glVertex2f(100,2.5);
    glVertex2f(100,6.5);
    glVertex2f(0,6.5);
    glVertex2f(0,2.5);

    glEnd();


    glPushMatrix();
    glTranslatef(+0.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
     glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();



    glPopMatrix();

   glLoadIdentity();
   //nicher rail line border....
    glColor3ub(93, 109, 126);
    glBegin(GL_POLYGON);
    glVertex2f(0,2.5);
    glVertex2f(100,2.5);
    glVertex2f(100,3);
    glVertex2f(0,3);
    glVertex2f(0,2.5);

    glEnd();
    //rail line er uporer border.....
    glColor3ub(93, 109, 126);
    glBegin(GL_POLYGON);
    glVertex2f(0,6.5);
    glVertex2f(100,6.5);
    glVertex2f(100,7);
    glVertex2f(0,7);
    glVertex2f(0,6.5);

    glEnd();
    //TRAIN ER body.....
    //TRAIN MOVING.....


    glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_train,0.0f, 0.0f);


    //train wheel....

    wheel_for_train(25,4,1);
    wheel_for_train(27,4,1);
    wheel_for_train(33,4,1);
    wheel_for_train(35,4,1);
    wheel_for_train(37,4,1);
    wheel_for_train(46,4,1);
    wheel_for_train(48,4,1);
    wheel_for_train(51,4,1);
    wheel_for_train(53,4,1);
    wheel_for_train(60,4,1);
    wheel_for_train(62,4,1);
    wheel_for_train(65,4,1);
    wheel_for_train(67,4,1);
    wheel_for_train(73,4,1);
    wheel_for_train(75,4,1);
    //engine...
    glColor3ub(100, 30, 22);
    glBegin(GL_POLYGON);
    glVertex2f(20,4);
    glVertex2f(27,4);
    glVertex2f(27,7);
    glVertex2f(20,7);
    glVertex2f(20,4);

    glEnd();
   //glass....

    glColor3ub(235, 237, 239);
    glBegin(GL_POLYGON);
    glVertex2f(22,7);
    glVertex2f(25,7);
    glVertex2f(25,10);
    glVertex2f(22,7);

    glEnd();
    glColor3ub(23, 32, 42);
      glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2f(22,7);
    glVertex2f(25,10);
    glVertex2f(22,7);
    glVertex2f(25,7);
     glVertex2f(25,7);
     glVertex2f(25,10);
    glEnd();

   //train engine er janala...

     glColor3ub(100, 30, 22);
    glBegin(GL_POLYGON);
    glVertex2f(25,7);
    glVertex2f(27,7);
    glVertex2f(27,10);
    glVertex2f(25,10);
    glVertex2f(25,7);

    glEnd();
    //engine back....
     glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(27,4);
    glVertex2f(35,4);
    glVertex2f(35,10);
    glVertex2f(27,10);
    glVertex2f(27,4);

    glEnd();
    //body one.....

    glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(35,4);
    glVertex2f(49,4);
    glVertex2f(49,10);
    glVertex2f(35,10);
    glVertex2f(35,4);

    glEnd();
   //body two.....
    glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(49,4);
    glVertex2f(63,4);
    glVertex2f(63,10);
    glVertex2f(49,10);
    glVertex2f(49,4);

    glEnd();
    //body three.....
    glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(63,4);
    glVertex2f(77,4);
    glVertex2f(77,10);
    glVertex2f(63,10);
    glVertex2f(63,4);

    glEnd();

    //border engine -1 bold....
     glColor3ub(151, 154, 154);
    glBegin(GL_POLYGON);
    glVertex2f(35,4);
    glVertex2f(35.5,4);
    glVertex2f(35.5,10);
    glVertex2f(35,10);
    glVertex2f(35,4);

    glEnd();

   //border 1-2 bold....

    glColor3ub(151, 154, 154);
    glBegin(GL_POLYGON);
    glVertex2f(49,4);
    glVertex2f(49.5,4);
    glVertex2f(49.5,10);
    glVertex2f(49,10);
    glVertex2f(49,4);

    glEnd();
    //border 2-3 bold.....
    glColor3ub(151, 154, 154);
    glBegin(GL_POLYGON);
    glVertex2f(63,4);
    glVertex2f(63.5,4);
    glVertex2f(63.5,10);
    glVertex2f(63,10);
    glVertex2f(63,4);

    glEnd();

    //train er window 1...
    glPushMatrix();
    glTranslatef(+0.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
     glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();

    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+4.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+4.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();

    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();

    glTranslatef(+4.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();


    glPopMatrix();

     glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(20,4);
    glVertex2f(21,4);
    glVertex2f(21,7);
    glVertex2f(20,7);
    glVertex2f(20,4);

    glEnd();
    //engine er janala alada kore draw.....
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(28,7);
    glVertex2f(30,7);
    glVertex2f(30,9);
    glVertex2f(28,9);
    glVertex2f(28,7);

    glEnd();


    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(32,7);
    glVertex2f(34,7);
    glVertex2f(34,9);
    glVertex2f(32,9);
    glVertex2f(32,7);

    glEnd();


    glPopMatrix();
    glLoadIdentity();
   //train er niche grass.....

  grass(4,0,4);
  grass(2,2,4);

  grass(19,0,3);
  grass(23,0,5);
  grass(27,0,3);

  grass(40,0,5);
  grass(38,3,3);
  grass(42,3,3);
  grass(45,2,3);
  grass(47,3,3);
  grass(48,0,3.2);

  grass(60,0,3);
  grass(64,1,4.5);
  grass(68,0,3);

  grass(100,0,6);
  grass(94,0,3);


    glFlush();

}

void screenTime(int value) {
     totalScreenTime+= perDisplayTime;

    if(totalScreenTime>=4*perDisplayTime)
    {
        currentScenario=1;
        totalScreenTime=0;

    }
    else if(totalScreenTime>=3*perDisplayTime)
    {
         currentScenario=4;

    }
    else if(totalScreenTime>=2*perDisplayTime)
    {
        currentScenario=3;

    }
    else if(totalScreenTime>=perDisplayTime)
    {
        currentScenario=2;
    }
    glutPostRedisplay();
    glutTimerFunc(15000, screenTime, 0);
}


void update2(int value) {
     init();
    // glutKeyboardFunc(keyBoardFun);
     glutTimerFunc(20, update_cloud, 0);
     glutTimerFunc(20,update_car,0);
     glutTimerFunc(20,update_truck,0);
     glutTimerFunc(200,update_bird,0);
     glutTimerFunc(20,update_train,0);
     glutTimerFunc(20,update_boat,0);
     glutTimerFunc(20,update_boat_two,0);
     glutTimerFunc(20,update_wave,0);
     glutTimerFunc(20,update_car_second,0);
     glutTimerFunc(60,update_boat_third,0);
    //glutSpecialFunc(SpecialInput);
    glutTimerFunc(15000,screenTime,0);
}

void display2() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f(1,1,1,0);


  day();
glutSwapBuffers();
   // glClear(GL_COLOR_BUFFER_BIT);
  //  glLoadIdentity();

    // Render only day and mountain for pagetwo
   //day();
  //  mountain();

   // glutSwapBuffers();
    glFlush();
}






 /** void myKeyboard(unsigned char key, int x, int y)
{
   if(key=='1')
    {
      sndPlaySound("train.wav", SND_ASYNC);
    }
    if(key=='2')
    {
      sndPlaySound("bus.wav", SND_ASYNC);

    }

    if(key=='3')
    {
      sndPlaySound("ocean.wav", SND_ASYNC);

    }
}



void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
    sndPlaySound("announcemet.wav", SND_ASYNC);

	}

	glutPostRedisplay();
}


void init (void)
{
   /// initialize viewing values
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}

/** Main function: GLUT runs as a console application starting at main()
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1520, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Cox's Bazar Railway Statio"); // Create a window with the given title

    init ();
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(handleMouse);

    glutIdleFunc(Idle);
    glutSpecialFunc(SpecialInput);
        #pragma comment(lib, "winmm.lib")



	glutMainLoop();///Enter the event-processing loop
    return 0;
}**/

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
         case '1': // <-- Corrected case for key '6'
            sndPlaySound("announcemet.wav", SND_ASYNC);
            glutDisplayFunc(display);
            break; // <-- Ends execution for '6' key

        case '2':
            if (!flag) {
                glutTimerFunc(500, update3, 0);
            }
            PlaySound("plane.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
            glutDisplayFunc(display3);
            break; // <-- Important! Ends execution for '1' key
      case '3':
           // PlaySound("plane.wav", NULL, SND_ASYNC );
            glutDisplayFunc(display2);
           // initializeTimers();
            PlaySound("birds.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
            glutTimerFunc(500, update2, 0);

            break; // <-- Important! Ends execution for '1' key


    }

     if(key=='4')
        {
          sndPlaySound("train.wav", SND_ASYNC|SND_FILENAME|SND_LOOP);
        }
        if(key=='5')
        {
          sndPlaySound("bus.wav", SND_ASYNC);

        }

        if(key=='6')
        {
          sndPlaySound("ocean.wav", SND_ASYNC);

        }
        glutPostRedisplay(); // Ensure the display updates
    }



void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		glutDisplayFunc(displayNavigation);
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		glutDisplayFunc(displayCover);
	}

	glutPostRedisplay();
}



/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080); // Set the window's initial width & height
    glutInitWindowPosition(0, 0);  // Set the window's initial position according to the monitor
    glutCreateWindow("Rail Station & City"); // Create a window with the given title
    glutDisplayFunc(displayCover); // Register display callback handler for window re-paint
    //glutIdleFunc(Idle);
    glutKeyboardFunc(handleKeypress);

        //init1();
    glutMouseFunc(handleMouse);
    glutIdleFunc(Idle);
    glutSpecialFunc(SpecialInput);


    //glutSpecialFunc(SpecialInput);

       // #pragma comment(lib, "winmm.lib")
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}




