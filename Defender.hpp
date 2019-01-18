#pragma once
#include "skills.h"

namespace MyStrategy
{
	void defender(BeliefState *state, int botID)
	{
		//print("Defender\n");
		//It follows the ball
		Vec2D dpoint;
		dpoint.x = -HALF_FIELD_MAXX / 2;
		dpoint.y = state->ballPos.y;
		Vec2D goal;
		goal.x = HALF_FIELD_MAXX ; 
		goal.y = (OPP_GOAL_MAXY+OPP_GOAL_MINY)/2;
    /*if(Vec2D::distSq(state->homePos[botID], state->ballPos) <= 6 * BOT_BALL_THRESH)
    {
      GoToBall(botID,state,true);
      GoToPoint(botID,state,goal,0,true,true);
    }*/
	  if ((state->ballPos.x >= -HALF_FIELD_MAXX*0.5) && (state->ballPos.x <= 0))
		{
			Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
			Vec2D dpoint(-HALF_FIELD_MAXX*0.5, state->ballPos.y);
			int awaybot = state->oppBotNearestToBall;
			if (Vec2D::distSq(state->awayPos[awaybot], state->ballPos) <= 6 * BOT_BALL_THRESH)
			{
				if (state->ballPos.y>=OUR_GOAL_MAXY)
					dpoint.y = OUR_GOAL_MAXY;
				if (state->ballPos.y<=OUR_GOAL_MINY)
					dpoint.y = OUR_GOAL_MINY;
				GoToPoint(botID, state, dpoint, 0 , true,false);
				if(Vec2D::distSq(state->homePos[botID], state->ballPos) <= 6 * BOT_BALL_THRESH)
				{
					GoToPoint(botID,state,goal,0,true,true);
				}
			}
			else
				GoToPoint(botID, state, ballPoint, 0, true, true);
		}
		else if (state->ballPos.x>=0)
		{
			dpoint.x = -HALF_FIELD_MAXX / 2;
			dpoint.y = state->ballPos.y;
			if (state->ballPos.y>(0.75)*HALF_FIELD_MAXY)
			    dpoint.y = (0.75)*HALF_FIELD_MAXY;
			if (state->ballPos.y<-(0.75)*HALF_FIELD_MAXY)
				dpoint.y = -(0.75)*HALF_FIELD_MAXY;
			GoToPoint(botID, state, dpoint, PI / 2, false, false);
		}
		//   GoToPoint(1,state,dpoint,PI/2,false,false);
		if (state->homePos[botID].x <= -HALF_FIELD_MAXX+1000)
		{
			dpoint.y = state->ballPos.y;
			dpoint.x = -HALF_FIELD_MAXX +2000;
			GoToPoint(botID, state, dpoint, PI / 2, false, false);
		}
		if ((state->homePos[botID].y<=OPP_GOAL_MAXY+600) && (state->homePos[botID].y>=0) && (state->homePos[botID].x >= HALF_FIELD_MAXX - 1000))
		{
			Vec2D dPoint(state->ballPos.x, OPP_GOAL_MAXY+600);
			GoToPoint(botID, state, dPoint, 0, false, true);
		}
		if ((state->homePos[botID].y >= OPP_GOAL_MINY-600) && (state->homePos[botID].y<=0) && (state->homePos[botID].x>=HALF_FIELD_MAXX - 1000))
		{
			Vec2D dPoint(state->ballPos.x, OPP_GOAL_MINY-600);
			GoToPoint(botID, state, dPoint, 0, false, true);
		}
		// part when ball is deep in our zone
	}
}