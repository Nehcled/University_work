# Generated by Django 3.2.9 on 2021-12-06 11:08

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('bonus', '0010_rename_pid_winner_prize_id'),
    ]

    operations = [
        migrations.AlterField(
            model_name='winner',
            name='prize_id',
            field=models.ForeignKey(default='', on_delete=django.db.models.deletion.CASCADE, to='bonus.prize'),
        ),
    ]
