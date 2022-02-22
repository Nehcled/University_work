from django.shortcuts import render
from .models import Prize,Winner
# Create your views here.

def index(request):
    prizeList = Prize.objects.all()
    winnerList = Winner.objects.all()

    return render(
        request,
        'bonus/index.html',
        context={'prize_list':prizeList,'winner_list':winnerList}
    )