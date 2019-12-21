Css.(
  global("html", [boxSizing(borderBox)]),
  global("*, *::before, *::after", [boxSizing(inherit_)]),
  global("*", [minWidth(zero), minHeight(zero)]),
  global("html, body", [margin(zero), padding(zero)]),
  global(
    "body",
    [
      color(hex("111")),
      fontSize(rem(1.)),
      fontFamily(
        "-apple-system, BlinkMacSystemFont, 'Segoe UI', 'Roboto', 'Oxygen',
        'Ubuntu', 'Cantarell', 'Fira Sans', 'Droid Sans', 'Helvetica Neue',
        sans-serif",
      ),
    ],
  ),
  global("h1,h2,h3,h4,h5,h6", [fontWeight(`num(500)), margin(zero)]),
  global("img", [width(pct(100.0)), height(auto)]),
);

ReactDOMRe.renderToElementWithId(<App />, "root");

module ServiceWorker = {
  [@bs.module "./serviceWorker"] external register: unit => unit = "register";
  [@bs.module "./serviceWorker"]
  external unregister: unit => unit = "unregister";
};

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
ServiceWorker.unregister();