# Generated by Django 3.2.9 on 2021-11-29 09:50

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('bonus', '0002_winner_prize_id'),
    ]

    operations = [
        migrations.RenameField(
            model_name='prize',
            old_name='prize_amount',
            new_name='amount',
        ),
        migrations.RenameField(
            model_name='prize',
            old_name='prize_cname',
            new_name='cname',
        ),
        migrations.RenameField(
            model_name='prize',
            old_name='prize_id',
            new_name='pid',
        ),
    ]
