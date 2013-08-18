#ifndef __TSC_H__
#define __TSC_H__

#include "ts.h"
#include "tsstr.h"

#if __cplusplus
extern "C"{
#endif
	//Semantic Values
	typedef struct _Operation{
		TSStr* component;
		TSStr* function;
	} Operation;

	typedef struct _PriExp{
		TSStr* token;
		int type;
	} PriExp;
	
	struct _ArgExpList;
	struct _Exp;

	typedef struct _PostExp{
		int type;
		union{
			PriExp *priExp;
			struct{
				PriExp *priExp;
				struct _ArgExpList* argList;
			}funCall;
			struct{
				Operation* op;
				struct _ArgExpList* argList;
			}opCall;
			struct _Exp* exp;
			_tsulong number;
			TSStr* strVal;
		}comp;
	}PostExp;

	struct _AssignExp;

	typedef struct _ArgExpList{
		int type;
		union{
			struct _AssignExp* assignExp;
			struct{
				struct _ArgExpList *argList;
				struct _AssignExp* assignExp;
			}mulArgList;
		}comp;
	} ArgExpList;

	typedef struct _UnaryExp{
		int type;
		union{
			struct _PostExp* postExp;
			struct _UnaryExp* unaryExp;
		}comp;
	}UnaryExp;

	typedef struct _MulExp{
		int type;
		union{
			UnaryExp* unaryExp;
			struct{
				struct _MulExp* mulExp;
				PostExp* postExp;
				int op;
			} caltor;
		}comp;
	}MulExp;

	typedef struct _AddExp{
		int type;
		union{
			MulExp* mulExp;
			struct{
				struct _AddExp* addExp;
				MulExp* mulExp;
				int op;
			} caltor;
		}comp;
	}AddExp;

	typedef struct _RelExp{
		int type;
		union{
			AddExp* addExp;
			struct {
				struct _RelExp* relExp;
				AddExp* addExp;
				int op;
			} caltor;
		}comp;
	}RelExp;

	typedef struct _EqExp{
		int type;
		union{
			RelExp* relExp;
			struct {
				struct _EqExp* eqExp;
				RelExp* relExp;
				int op;
			} caltor;
		}comp;
	}EqExp;

	typedef struct _LogAndExp{
		int type;
		union{
			EqExp* eqExp;
			struct {
				struct _LogAndExp* logExp;
				EqExp* eqExp;
			} caltor;
		}comp;
	}LogAndExp;

	typedef struct _LogOrExp{
		int type;
		union{
			LogAndExp *andExp;
			struct{
				struct _LogOrExp *orExp;
				LogAndExp *andExp;
			} caltor;
		}comp;
	}LogOrExp;

	typedef struct _CondExp{
		int type;
		union{
			LogOrExp *orExp;
			struct{
				LogOrExp *orExp;
				struct _Exp *exp;
				struct _CondExp *condExp;
			}mulCaltor;
		}comp;
	} CondExp;

	typedef struct _AssignExp{
		int type;
		union{
			CondExp* condExp;
			struct{
				TSStr* strVal;
				int op;
				struct _AssignExp *assignExp;
			}exp;
		}comp;
	}AssignExp;

	typedef struct _Exp{
		int type;
		union{
			AssignExp* assignExp;
			struct{
				struct _Exp *exp;
				AssignExp* assignExp;
			}mulExp;
		}comp;
	} Exp;

	typedef struct _IDList{
		int type;
		union{
			TSStr* id;
			struct{
				struct _IDList* ilist;
				TSStr* id;
			}mulExp;
		}comp;
	}IDList;

	struct _CompStmt;
	struct _ExpStmt;
	struct _SelStmt;
	struct _ItorStmt;

	typedef struct _Stmt{
		int type;
		union{
			struct _CompStmt *compStmt;
			struct _ExpStmt *expStmt;
			struct _SelStmt *selStmt;
			struct _ItorStmt *itorStmt;
		}comp;
	} Stmt;

	struct _StmtList;

	typedef struct _CompStmt{
		int type;
		struct _StmtList *stmtList;
	}CompStmt;

	typedef struct _StmtList{
		int type;
		union{
			Stmt* stmt;
			struct{
				struct _StmtList* slist;
				Stmt* stmt;
			}list;
		}comp;
	}StmtList;

	typedef struct _ExpStmt{
		int type;
		Exp* exp;
	}ExpStmt;

	typedef struct _SelStmt{
		int type;
		Exp* exp;
		Stmt *ifStmt;
		Stmt *elStmt;
	}SelStmt;

	typedef struct _ItorStmt{
		int type;
		union{
			struct {
				Exp* exp;
				Stmt* stmt;
			}wstmt;
			struct{
				ExpStmt* expStmt1;
				ExpStmt* expStmt2;
				Exp* exp;
				Stmt* stmt;
			}fstmt;
		}comp;
	}ItorStmt;

	struct _ExtDecl;
	struct _FunDef;

	typedef struct _TransUnit{
		int type;
		union{
			struct _ExtDecl *extDecl;
			struct {
				struct _TransUnit *transUnit;
				struct _ExtDecl *extDecl;
			}mulUnit;
		}comp;
	}TransUnit;

	typedef struct _ExtDecl{
		int type;
		union{
			struct _FunDef *funDef;
			CompStmt *compStmt;
		}comp;
	}ExtDecl;

	typedef struct _FunDef{
		TSStr* name;
		IDList* ilist;
		CompStmt* compStmt;
	}FunDef;

	//Auxiliary functions
	_tsulong StrToNum(TSStr* str);
#if __cplusplus
};
#endif
#endif __TSC_H__