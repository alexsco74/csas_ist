(function ($) {

    $.fn.csasIstImagesReveal = function (itI) {
        var iso = this.data('isotope');
        var itemSelector = iso.options.itemSelector;

        // hide by default
        itI.hide();

        // append to container
        this.append(itI);

        itI.imagesLoaded().progress(function (imgLoad, image) {

            // get item
            // image is imagesLoaded class, not <img>, <img> is image.img
            var $item = $(image.img).parents(itemSelector);
            if (!$item.hasClass('csas-ist-item-added')) {
                $item.addClass('csas-ist-item-added');

                // un-hide item
                $item.show();

                // isotope does its thing
                iso.appended($item);
            }
        });
        this.isotope('layout');
        return this;
    };

    function csasIstInit(context, settings) {
        $('.csas-ist-grid', context).once('csas-ist-prs', function () {
            var thisOptions = {};

            if ($(this).attr('data-options') != undefined) {
                thisOptions = JSON.parse($(this).attr('data-options'));
            }

            var tE = $(this);
            var ist = $(this).isotope(thisOptions);

            ist.imagesLoaded().progress(function () {
                ist.isotope('layout');
            });

            ist.bind('csasVapAppendItems', function (e, nI) {
                var niE = $(nI);
                ist.csasIstImagesReveal(niE);
                if(typeof Drupal.behaviors.initColorboxInline != undefined) {
                    Drupal.behaviors.initColorboxInline.attach(context, settings);
                }
            });
        });
    };

    Drupal.behaviors.csasIst = {
        attach: function (context, settings) {
            csasIstInit(context, settings);
        }
    };

    $(document).on("DOMNodeInserted", function (e) {
        if ($(e.target).hasClass('csas-ist-grid')) {
            csasIstInit(document, {});
        }
    });


})(jQuery);