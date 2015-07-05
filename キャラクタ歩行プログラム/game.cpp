/******************************************************************************
* File Name : game.c                             Ver : 1.00  Date : 2003-01-04
*
* Description :
*
*       �L�����N�^�̕��s�A�j���[�V�����̃T���v���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include    "game.h"
#include    <gslib.h>
#include "Move.h"
 enum Graph
{
	IMO
};
/****** �O���[�o���ϐ��錾 ***************************************************/

static float        x = 0.0f;       /* �����W               */
static float        y = 0.0f;       /* �����W               */
static float        z = 0.0f;       /* �����W               */
static float        a = 0.0f;       /* �ړ�����             */
static float        s = 0.0f;       /* �ړ��X�s�[�h         */
static float        t = 0.0f;       /* �A�j���[�V�����^�C�} */

static float s_timer = 0.0f;
static float s_angle = 0.0f;
static float posX = 0;
static float posY = 0;
static float posZ = 0;
static float speed = 0;

Move move;

/*=============================================================================
*
* Purpose : �Q�[���������D
*
* Return  : �Ȃ�
*
*============================================================================*/
void gameInit( void )
{
    /* ���b�V���t�@�C���̓ǂݍ��� */
    gsLoadMesh( IMO, "./res/kyudo.msh" );

    /* �X�P���g���t�@�C���̓ǂݍ��� */
    gsLoadSkeleton( IMO, "./res/kyudo.skl" );

    /* �A�j���[�V�����t�@�C���̓ǂݍ��� */
    gsLoadAnimation( IMO, "./res/kyudo.anm" );

    /* �X�L�j���O���b�V����L���ɂ��� */
    gsEnable( GS_SKIN_MESH );
}

/*=============================================================================
*
* Purpose : �Q�[�����C�������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void gameMain( void )
{
	s_timer++;
	move.movePos(posX, posY, posZ, speed, s_angle);
	move.moveAngle(s_angle);
}

/*=============================================================================
*
* Purpose : �Q�[���`�揈���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void gameDraw( void )
{
	/*�A�j���̃o�C���h*/
	gsBindAnimation(IMO,IMO,s_timer);
	/*�X�P���g���̃o�C���h*/
	gsBindSkeleton(IMO);

	/*���b�V���̕`��*/
	glPushMatrix();
		glTranslatef(posX, posY, posZ);
		glRotatef(s_angle, 0.0f, 1.0f, 0.0f);
		gsDrawMesh(IMO);
	glPopMatrix();
}

/*=============================================================================
*
* Purpose : �Q�[���I�������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void gameFinish( void )
{
    /* ���b�V�����폜 */
    gsDeleteMesh( IMO );

    /* �X�P���g�����폜 */
    gsDeleteSkeleton( IMO );

    /* �A�j���[�V�������폜 */
    gsDeleteAnimation( IMO);
}

/********** End of File ******************************************************/


