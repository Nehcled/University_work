from django.db import models
# basic config of enter data(maybe)
# Create your models here.
class Prize(models.Model):
    pid = models.CharField(max_length=20)
    cname = models.CharField(max_length=20)
    amount = models.IntegerField()

    def __str__(self):
        return self.cname
  
class Winner(models.Model):
    last_ssn = models.CharField(max_length=3)
    prize_id = models.ForeignKey("Prize", on_delete=models.CASCADE,default="")
    
    def __str__(self):
        return self.prize_id.cname + ", " + self.last_ssn