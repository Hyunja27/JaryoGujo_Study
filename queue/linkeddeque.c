
#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque* tmp = malloc(sizeof(LinkedDeque));

	tmp->currentElementCount = 0;
	tmp->pFrontNode = 0;
	tmp->pRearNode = 0;

	return (tmp);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	if (!pDeque)
		return(-1);
	if (pDeque->currentElementCount == 0)
	{
		pDeque->pFrontNode = &element;
		pDeque->pRearNode = &element;
	}
	else
	{
		element.pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode->pLLink = &element;
		pDeque->pFrontNode = &element;
	}

	pDeque->currentElementCount += 1;
	return (pDeque->currentElementCount);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	if (!pDeque)
		return(-1);
	if (pDeque->currentElementCount == 0)
	{
		pDeque->pFrontNode = &element;
		pDeque->pRearNode = &element;
	}
	else
	{
		element.pRLink = pDeque->pRearNode;
		pDeque->pRearNode->pLLink = &element;
		pDeque->pRearNode = &element;
	}

	pDeque->currentElementCount += 1;
	return (pDeque->currentElementCount);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	if (!pDeque || (pDeque->currentElementCount == 0))
		return(NULL);
	
	DequeNode *tmp = pDeque->pFrontNode;

	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	pDeque->pFrontNode->pLLink = NULL;

	free(tmp);

	pDeque->currentElementCount -= 1;
	return (pDeque->pFrontNode);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	if (!pDeque || (pDeque->currentElementCount == 0))
		return(NULL);
	
	DequeNode *tmp = pDeque->pRearNode;

	pDeque->pRearNode = pDeque->pReartNode->pLLink;
	pDeque->pRearNode->pRLink = NULL;

	free(tmp);

	pDeque->currentElementCount -= 1;
	return (pDeque->pRearNode);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	if (pDeque->currentElementCount == 0)
		return ;
	DequeNode *tmp = pDeque->pFrontNode;
	DequeNode *target;
	while (tmp != pDeque->pRearNode)
	{
		target = tmp;
		tmp = tmp->pRLink;
		free(target);
	}
	free(tmp);
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
	//?
	return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (pDeque->currentElementCount == 0)
		return TRUE;
	else
		return FALSE;
}
