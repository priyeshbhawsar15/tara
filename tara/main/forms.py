from django import forms
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User

class NewUserForm(UserCreationForm):
    email = forms.EmailField(required=True)
    number = forms.IntegerField(required=True)
    number1 = forms.IntegerField(required=True)
    number2 = forms.IntegerField(required=True)
    name = forms.CharField(required=True)
    class Meta:
        model = User
        fields = ("username", "name", "email", "password1", "number", "number1", "number2")

    def save(self, commit=True):
        user = super(NewUserForm, self).save(commit=False)
        user.name = self.cleaned_data["name"]
        user.email = self.cleaned_data["email"]
        user.number = self.cleaned_data["number"]
        user.number1 = self.cleaned_data["number1"]
        user.number2 =  self.cleaned_data["number2"]
        if commit:
            user.save()
        return user