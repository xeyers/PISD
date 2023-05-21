przenies()
{
	///dodac licznik elementow
	if(counter < 3) return;
	else
	{
		//ultimate stop porzucony na rzecz liczenia ilosci par
		Node* runner = head; int ilePar = 0;
		while(runner != nullptr && runner->next != nullptr)
		{
			runner = runner->next->next;
			ilePar++;
		}
		
		runner = head;
		while(runner->next != nullptr)
		{
			runner = runner->next;
		}
		Node* tail = runner; //miedzy ten element a jego nastepny beda wchodzily
							 //te przepinane na koniec
		
		Node* one = head, *two = one->next, *preGroup = nullptr, *last = nullptr;
		//last jest zawsze na ostatnim oczku ostatniej dopietej
		//na poczatek pary
		//preGroup jest zawsze oczko przed one
		int ileBylo = 0;
		while(one != nullptr  && two != nullptr && ileBylo < ilePar)
		{
			if(one->data == two->data)
			{
				if(preGroup == nullptr) //pierwsza para
				{
					last = two;
					preGroup = two;
					
					one = preGroup->next;
					if(one != nullptr) two = one->next;
					else two = nullptr;
				}
				else
				{
					preGroup->next = two->next;
					two->next = last->next;
					last->next = one;
					last = two;
					
					one = preGroup->next;
					if(one != nullptr) two = one->next;
					else two = nullptr;
				}
			}
			else
			{
					one->next = two->next;
					two->next = tail->next; //nullptr dla pierwszej pary
					tail->next = two;
					
					preGroup = one;
					preGroup->next = one;
					if(one != nullptr) two = one->next;
					else two = nullptr;
			}
		}
	}
}
