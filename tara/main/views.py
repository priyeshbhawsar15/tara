from django.shortcuts import render
from .models import DButton
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.contrib.auth import logout, authenticate, login
from django.contrib import messages
from .forms import NewUserForm
from django.core.mail import send_mail



# Create your views here.

def register(request):
    if request.method == "POST":
        form = UserCreationForm(request.POST)
        if form.is_valid():
            user = form.save()
            username = form.cleaned_data.get('username')
            messages.success(request, f"New account created: {username}")
			login(request, user)
            return redirect("main:homepage")

        else:
            for msg in form.error_messages:
                messages.error(request, f"{msg}: {form.error_messages[msg]}")

            return render(request = request,
                          template_name = "main/register.html",
                          context={"form":form})

    form = UserCreationForm
    return render(request = request,
                  template_name = "main/register.html",
                  context={"form":form})

   def logout_request(request):
    logout(request)
    messages.info(request, "Logged out successfully!")
    return redirect("main:homepage")


    def login_request(request):
    if request.method == 'POST':
        form = AuthenticationForm(request=request, data=request.POST)
        if form.is_valid():
            username = form.cleaned_data.get('username')
            password = form.cleaned_data.get('password')
            user = authenticate(username=username, password=password)
            if user is not None:
                login(request, user)
                messages.info(request, f"You are now logged in as {username}")
                return redirect('/')
            else:
                messages.error(request, "Invalid username or password.")
        else:
            messages.error(request, "Invalid username or password.")
    form = AuthenticationForm()
    return render(request = request,
                    template_name = "main/login.html",
                    context={"form":form})
datatuple = (
    ('Emergengy Alert from '+ username, 'I am in trouble. Save Me!', email, 'some@email.com'),
    ('Emergengy Alert from '+ username, 'I am in trouble. Save Me!', email, email1),
	('Emergengy Alert from' + username, 'I am in trouble. Save Me!', email, email2),
	('Emergengy Alert from' + username, 'I am in trouble. Save Me!', email, email3),
	('Emergengy Alert from' + username, 'I am in trouble. Save Me!', email, email4),
)
	
	
	def sendemail(request):
		send_mass_mail(datatuple)


