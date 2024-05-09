const openButtons = document.getElementsByClassName("open");
const modal = document.getElementById("myWindow");
const modalImg = document.getElementById("img01");
const captionText = document.getElementById("window-bildname");
const closeModal = document.getElementsByClassName("close")[0];

// Fügt jedem "open-button" einen EventListener hinzu
for (let i = 0; i < openButtons.length; i++) {
	openButtons[i].addEventListener("click", function () {
		let imageBox = this.parentNode.parentNode;
		let image = imageBox.querySelector("img");
		modal.style.display = "flex"; // Stellt das Modal auf flex, sodass es teil des DOM wird und transformierbar ist
		setTimeout(() => {
			modal.classList.add("show"); // Fügt die Klasse 'show' hinzu für die Animation
		}, 1); // Kurze Verzögerung, um CSS-Transitions zu ermöglichen
		modalImg.src = image.src;
		captionText.innerHTML = image.alt;
	});
}

// Schließen des Modals mit dem 'close' Button
closeModal.addEventListener("click", function () {
	modal.classList.remove("show");
	setTimeout(() => (modal.style.display = "none"), 500); // Stellt sicher, dass das Modal erst verschwindet, wenn die Animation abgeschlossen ist
});

// Schließen des Modals, wenn außerhalb des Inhalts geklickt wird
document.addEventListener("click", function (event) {
	if (event.target === modal) {
		modal.classList.remove("show");
		setTimeout(() => (modal.style.display = "none"), 500); // Wartet bis die Schließanimation fertig ist
	}
});
