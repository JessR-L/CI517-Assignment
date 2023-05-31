#ifndef __MY_ENGINE_H__
#define __MY_ENGINE_H__

#include "../EngineCommon.h"

class MyEngine {
	friend class XCube2Engine;
	private:
		

	public:
		MyEngine();
		MyEngine(int start_x, int start_y, int npc_width, int npc_height);
		
		void movement(int target_x, int target_y);

		int x, y, width, height;
		int tarY, tarX;

		bool reachedTarget;

};

#endif