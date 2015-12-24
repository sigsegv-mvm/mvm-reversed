/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/NextBot/NavMeshEntities/func_nav_prerequisite.h
 */


// TODO: IFuncNavPrerequisiteAutoList


class CFuncNavPrerequisite : public CBaseTrigger,
	public IFuncNavPrerequisiteAutoList
{
public:
	enum TaskType : int
	{
		// 0 none?
		// 1 destroy?
		MOVE_TO = 2,
		WAIT    = 3,
	};
	
	// TODO
};
