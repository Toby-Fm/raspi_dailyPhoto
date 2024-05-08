const openButtons = document.getElementsByClassName("open");
const modal = document.getElementById("myWindow");
const modalImg = document.getElementById("img01");
const captionText = document.getElementById("window-bildname");
const closeModal = document.getElementsByClassName("close")[0];

// Fügt jedem "open-button" einen EventListener hinzu
for (let i = 0; i < openButtons.length; i++) {
	openButtons[i].addEventListener("click", function () {
		// holt sich das Bild und den Bildnamen aus dem übergeordneten Element
		let imageBox = this.parentNode.parentNode;
		let image = imageBox.querySelector("img");
		modal.style.display = "block";
		modalImg.src = image.src;
		captionText.innerHTML = image.alt;
	});
}

// schließen
closeModal.addEventListener("click", function () {
	modal.style.display = "none";
});

document.addEventListener("click", function (event) {
	if (event.target === modal) {
		modal.style.display = "none";
	}
});
