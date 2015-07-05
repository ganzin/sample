/******************************************************************************
* File Name : game.h                             Ver : 1.00  Date : 2003-01-04
*
* Description :
*
*		�ȈՃQ�[���t���[�����[�N�w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GAME_H_
#define		_GAME_H_

#include	<GL/glut.h>
#include	<gslib.h>

/*---- �E�B���h�E�p�����[�^ -------------------------------------------------*/

#define	WINDOW_TITLE		"GameWindow"	/* �E�B���h�E�^�C�g��	*/
#define	WINDOW_POSX			0				/* �E�B���h�E�̂����W	*/
#define	WINDOW_POSY			0				/* �E�B���h�E�̂����W	*/
#define	WINDOW_WIDTH		640				/* �E�B���h�E�̕�		*/
#define	WINDOW_HEIGHT		480				/* �E�B���h�E�̍���		*/
#define	FULL_SCREEN_MODE	0				/* �t���X�N���[�����[�h	*/
#define	GAME_MODE_STRING	"640x480:32@60"	/* ��ʃ��[�h			*/

/*---- ����ϊ��p�����[�^ ---------------------------------------------------*/

#define	PERSPECTIVE_FOV		50.0f			/* ����p				*/
#define	PERSPECTIVE_NEAR	0.1f			/* �߃N���b�v��			*/
#define	PERSPECTIVE_FAR		100.0f			/* ���N���b�v��			*/

/*---- �E�F�C�g�^�C�} -------------------------------------------------------*/

#define	FPS_WAIT_TIME		( 1000 / 60 )	/* �e�o�r�E�F�C�g�^�C�} */

/****** �֐��v���g�^�C�v�錾 *************************************************/

extern void gameInit( void );				/* �Q�[������������		*/
extern void gameMain( void );				/* �Q�[�����C������		*/
extern void gameDraw( void );				/* �Q�[���`�揈��		*/
extern void gameFinish( void );				/* �Q�[���I������		*/

#endif

/********** End of File ******************************************************/
