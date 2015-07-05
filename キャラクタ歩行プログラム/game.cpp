/******************************************************************************
* File Name : game.c                             Ver : 1.00  Date : 2003-01-04
*
* Description :
*
*       キャラクタの歩行アニメーションのサンプル．
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
/****** グローバル変数宣言 ***************************************************/

static float        x = 0.0f;       /* ｘ座標               */
static float        y = 0.0f;       /* ｙ座標               */
static float        z = 0.0f;       /* ｚ座標               */
static float        a = 0.0f;       /* 移動方向             */
static float        s = 0.0f;       /* 移動スピード         */
static float        t = 0.0f;       /* アニメーションタイマ */

static float s_timer = 0.0f;
static float s_angle = 0.0f;
static float posX = 0;
static float posY = 0;
static float posZ = 0;
static float speed = 0;

Move move;

/*=============================================================================
*
* Purpose : ゲーム初期化．
*
* Return  : なし
*
*============================================================================*/
void gameInit( void )
{
    /* メッシュファイルの読み込み */
    gsLoadMesh( IMO, "./res/kyudo.msh" );

    /* スケルトンファイルの読み込み */
    gsLoadSkeleton( IMO, "./res/kyudo.skl" );

    /* アニメーションファイルの読み込み */
    gsLoadAnimation( IMO, "./res/kyudo.anm" );

    /* スキニングメッシュを有効にする */
    gsEnable( GS_SKIN_MESH );
}

/*=============================================================================
*
* Purpose : ゲームメイン処理．
*
* Return  : なし．
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
* Purpose : ゲーム描画処理．
*
* Return  : なし．
*
*============================================================================*/
void gameDraw( void )
{
	/*アニメのバインド*/
	gsBindAnimation(IMO,IMO,s_timer);
	/*スケルトンのバインド*/
	gsBindSkeleton(IMO);

	/*メッシュの描画*/
	glPushMatrix();
		glTranslatef(posX, posY, posZ);
		glRotatef(s_angle, 0.0f, 1.0f, 0.0f);
		gsDrawMesh(IMO);
	glPopMatrix();
}

/*=============================================================================
*
* Purpose : ゲーム終了処理．
*
* Return  : なし．
*
*============================================================================*/
void gameFinish( void )
{
    /* メッシュを削除 */
    gsDeleteMesh( IMO );

    /* スケルトンを削除 */
    gsDeleteSkeleton( IMO );

    /* アニメーションを削除 */
    gsDeleteAnimation( IMO);
}

/********** End of File ******************************************************/


