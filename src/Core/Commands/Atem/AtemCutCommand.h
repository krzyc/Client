#pragma once

#include "../../Shared.h"
#include "../AbstractCommand.h"

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QXmlStreamWriter>

class CORE_EXPORT AtemCutCommand : public AbstractCommand
{
    Q_OBJECT

    public:
        explicit AtemCutCommand(QObject* parent = 0);

        virtual void readProperties(boost::property_tree::wptree& pt);
        virtual void writeProperties(QXmlStreamWriter* writer);

        const QString& getStep() const;
        bool getTriggerOnNext() const;
        const QString& getMixerStep() const;

        void setStep(const QString& step);
        void setTriggerOnNext(bool triggerOnNext);
        void setMixerStep(const QString& mixerStep);

    private:
        QString step;
        bool triggerOnNext;
        QString mixerStep;

        Q_SIGNAL void stepChanged(const QString&);
        Q_SIGNAL void triggerOnNextChanged(bool);
        Q_SIGNAL void mixerStepChanged(const QString&);
};
